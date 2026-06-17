#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// create a global variable -- count = 0.
//  thread1 will increment variable 10 times.
//  thread2 will decrement variable 10 times.
//  print final count in main() -- expected 0.

int count = 0;

void *incr(void *param)
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        count = count + 1;
        // printf("incr: %d\n", count);
        //     sleep(1);
    }
    return NULL;
}

void *decr(void *param)
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        count = count - 1;
        // printf("decr: %d\n", count);
        //     sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t it, dt;
    pthread_create(&it, NULL, incr, NULL);
    pthread_create(&dt, NULL, decr, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", count);
    return 0;
}

/*
Inter-thread commn is more efficient/simple than inter-process commn.
Data section/Heap sections are accessible for all the threads (in that process).

Multiple threads (it & dt) accessing shared resource (count var) concurrently
may cause the "race condition". It will produce unexpected results.

Solution to Race condition -- Sychronization.
    - POSIX Sync Objects -- Semaphore, Mutex, Condition Variable.
*/
