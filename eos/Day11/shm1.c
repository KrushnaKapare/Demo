#include <stdio.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234

typedef struct shm
{
    int cnt;
} shm_t;

int main()
{
    int shmid;
    shm_t *ptr;
    // create shared memory
    shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT | 0600);
    // get pointer to shared memory
    ptr = (shm_t *)shmat(shmid, NULL, 0);
    // write and read from shared memory
    ptr->cnt = 0;                     // shm wr
    ptr->cnt++;                       // shm rd & wr
    printf("count = %d\n", ptr->cnt); // shm rd

    printf("press enter to exit...\n");
    getchar();
    // release pointer of shared memory
    shmdt(ptr);
    // destroy shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
