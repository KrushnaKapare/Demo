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

Semaphore: <semaphore.h>
    - declare semaphore object (will always have a single counter).
        - sem_t s;
        - declare so that it is accessible to the threads to be sychronized.
            - global - in data section - accessible to all threads in same process.
            - in shared memory - accessible to threads across the processes.
    - initialize semaphore
        - sem_init(&s, pshared, init_cnt);
            - arg1: semaphre obj (out param)
            - arg3: initial sema count
            - arg2: process shared
                - 0 -- for sync betn threads of the same process.
                - non-zero (key) -- for sync betn threads of the different processes.
    - destroy semaphore
        - sem_destroy(&s);
    - P operation
        - sem_wait(&s);
        - sem_trywait(...); // refer docs
        - sem_timedwait(...); // refer docs
    - V operation
        - sem_post(&s);
*/

int count = 0;
sem_t s; // declare semaphore globally -- accessible to inc & dec thread

void *incr(void *param)
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        sem_wait(&s); // P(s);
        count = count + 1;
        sem_post(&s); // V(s);
    }
    return NULL;
}

void *decr(void *param)
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        sem_wait(&s); // P(s);
        count = count - 1;
        sem_post(&s); // V(s);
    }
    return NULL;
}

int main()
{
    pthread_t it, dt;
    // create semaphore with initial value 1
    sem_init(&s, 0, 1);
    pthread_create(&it, NULL, incr, NULL);
    pthread_create(&dt, NULL, decr, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", count);
    // destroy semaphore
    sem_destroy(&s);
    return 0;
}
