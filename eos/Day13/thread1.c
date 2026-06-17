#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// demo of single threaded application.
//  single thread = main thread.
//  > ps -A -m -o pid,tid,nlwp,cmd
//  > cat /proc/<pid>/maps

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
    int i;
    incr(NULL);
    decr(NULL);
    for (i = 1; i <= 10; i++)
    {
        printf("main: %d\n", i);
        sleep(1);
    }
    return 0;
}