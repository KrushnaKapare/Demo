#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234

typedef struct shm
{
    int cnt;
} shm_t;

int main()
{
    int i, shmid, pid, s;
    shm_t *ptr;
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
            ptr->cnt--;                           // shm rd & wr
            printf("dec count = %d\n", ptr->cnt); // shm rd
        }
    }
    else
    {
        // parent increment count
        for (i = 1; i <= 1000; i++)
        {
            ptr->cnt++;                           // shm rd & wr
            printf("inc count = %d\n", ptr->cnt); // shm rd
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
    return 0;
}
