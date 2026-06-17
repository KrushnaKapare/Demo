#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// create a global variable -- count = 0.
//  thread1 will increment variable 10 times.
//  thread2 will decrement variable 10 times.
//  print final count in main() -- expected 0.

/*
Solution to Race condition -- Sychronization.
    - POSIX Sync Objects -- Semaphore, Mutex, Condition Variable.

Mutex - <pthread.h>
    - declare a mutex
        - pthread_mutex_t m;
    - init the mutex
        - pthread_mutex_init(&m, NULL);
            - arg1: mutex obj (out)
            - arg2: mutex attributes -- NULL means default attributes
    - destroy the mutex
        - pthread_mutex_destroy(&m);
    - lock the mutex
        - pthread_mutex_lock(&m);
        - pthread_mutex_trylock(...); // refer docs
        - pthread_mutex_timedwait(...); // refer docs
    - unlock the mutex
        - pthread_mutex_unlock(&m);
*/

int count = 0;
pthread_mutex_t m; // declare mutex globally -- accessible to inc & dec thread

void *incr(void *param)
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        pthread_mutex_lock(&m); // lock mutex
        count = count + 1;
        pthread_mutex_unlock(&m); // unlock mutex
    }
    return NULL;
}

void *decr(void *param)
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        pthread_mutex_lock(&m); // lock mutex
        count = count - 1;
        pthread_mutex_unlock(&m); // unlock mutex
    }
    return NULL;
}

int main()
{
    pthread_t it, dt;
    // create mutex with default attrs
    pthread_mutex_init(&m, NULL);
    pthread_create(&it, NULL, incr, NULL);
    pthread_create(&dt, NULL, decr, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", count);
    // destroy mutex
    pthread_mutex_destroy(&m);
    return 0;
}
