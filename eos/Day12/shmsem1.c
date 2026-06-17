#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x1234
#define SEM_KEY 0x4321

typedef struct shm
{
    int cnt;
} shm_t;

union semun
{
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
};

int main()
{
    int i, shmid, semid, pid, s;
    shm_t *ptr;
    union semun su;
    struct sembuf ops[1];
    // create semaphore with single counter
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0600);
    // initialize semaphore counter to 1
    su.val = 1;
    semctl(semid, 0, SETVAL, su);
    // create shared memory (no processes attached i.e. nattach cnt=0)
    shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT | 0600);
    // get pointer to shared memory -- increment shm nattach cnt (=1)
    ptr = (shm_t *)shmat(shmid, NULL, 0);
    ptr->cnt = 0; // shm wr
    // create child process -- now child also have ptr to shm, so nattach cnt is incremented (=2)
    pid = fork();
    if (pid == 0)
    {
        // child decrement count
        for (i = 1; i <= 1000; i++)
        {
            // P(s);
            ops[0].sem_num = 0; // sem idx
            ops[0].sem_op = -1; // P op
            ops[0].sem_flg = 0;
            semop(semid, ops, 1);
            ptr->cnt--;                           // shm rd & wr
            printf("dec count = %d\n", ptr->cnt); // shm rd
            // V(s);
            ops[0].sem_num = 0; // sem idx
            ops[0].sem_op = +1; // V op
            ops[0].sem_flg = 0;
            semop(semid, ops, 1);
        }
    }
    else
    {
        // parent increment count
        for (i = 1; i <= 1000; i++)
        {
            // P(s);
            ops[0].sem_num = 0; // sem idx
            ops[0].sem_op = -1; // P op
            ops[0].sem_flg = 0;
            semop(semid, ops, 1);

            ptr->cnt++;                           // shm rd & wr
            printf("inc count = %d\n", ptr->cnt); // shm rd
            // V(s);
            ops[0].sem_num = 0; // sem idx
            ops[0].sem_op = +1; // V op
            ops[0].sem_flg = 0;
            semop(semid, ops, 1);
        }
        wait(&s);
        printf("final count = %d\n", ptr->cnt);
        // mark shared memory for destruction -- will be destroyed when nattach cnt become zero.
        shmctl(shmid, IPC_RMID, NULL);
    }
    // release pointer of shared memory -- detach nattach cnt of shm.
    //  when child detach, nattach cnt become 1
    //  when parent detach, nattach cnt become 0 -- then shm is destroyed.
    shmdt(ptr);
    // destroy the sema -- in parent
    if (pid != 0)
        semctl(semid, 0, IPC_RMID);
    return 0;
}
