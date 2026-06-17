#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// demo of multi-threaded application.
//  1st thread = main thread.
//  new threads created using pthread_create()
//  > ps -A -m -o pid,tid,nlwp,cmd
//  > cat /proc/<pid>/maps
//      - observe stacks for new threads (below [heap] section)

void *incr(void *param)
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("incr: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void *decr(void *param)
{
    int i;
    for (i = 10; i >= 1; i--)
    {
        printf("decr: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t it, dt;
    int i;
    pthread_create(&it, NULL, incr, NULL);
    pthread_create(&dt, NULL, decr, NULL);
    for (i = 1; i <= 10; i++)
    {
        printf("main: %d\n", i);
        sleep(1);
    }
    return 0;
}