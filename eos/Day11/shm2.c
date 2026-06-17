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
    // create shared memory
    shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT | 0600);
    // get pointer to shared memory
    ptr = (shm_t *)shmat(shmid, NULL, 0);
    ptr->cnt = 0; // shm wr
    // create child process
    pid = fork();
    if (pid == 0)
    {
        // child decrement count
        for (i = 1; i <= 10; i++)
        {
            ptr->cnt--;                           // shm rd & wr
            printf("dec count = %d\n", ptr->cnt); // shm rd
            sleep(1);
        }
    }
    else
    {
        // parent increment count
        for (i = 1; i <= 10; i++)
        {
            ptr->cnt++;                           // shm rd & wr
            printf("inc count = %d\n", ptr->cnt); // shm rd
            sleep(1);
        }
        wait(&s);
        printf("final count = %d\n", ptr->cnt);
    }
    // release pointer of shared memory
    shmdt(ptr);
    // destroy shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
