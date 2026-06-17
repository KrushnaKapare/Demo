#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// send start & end num to a thread.
// thread will sum the range of numbers and return the result.

typedef struct range
{
    int start;
    int end;
} range_t;

void *range_sum(void *param)
{
    range_t *ptr = (range_t *)param;
    int num, sum = 0;
    for (num = ptr->start; num <= ptr->end; num++)
    {
        sum = sum + num;
        sleep(1);
    }
    printf("range sum - %d to %d = %d\n", ptr->start, ptr->end, sum);
    int *res = (int *)malloc(sizeof(int));
    *res = sum;
    return res;
}

/*
int main()
{
    pthread_t t1;
    range_t r1 = {.start = 1, .end = 10};
    int *res1;
    pthread_create(&t1, NULL, range_sum, &r1);
    pthread_join(t1, (void **)&res1);
    printf("t1 result = %d\n", *res1);
    free(res1);
    pthread_t t2;
    range_t r2 = {.start = 11, .end = 15};
    int *res2;
    pthread_create(&t2, NULL, range_sum, &r2);
    pthread_join(t2, (void **)&res2);
    printf("t2 result = %d\n", *res2);
    free(res2);
    printf("bye!\n");
    return 0;
}
*/

int main()
{
    pthread_t t1;
    range_t r1 = {.start = 1, .end = 10};
    int *res1;
    pthread_create(&t1, NULL, range_sum, &r1);
    pthread_t t2;
    range_t r2 = {.start = 11, .end = 15};
    int *res2;
    pthread_create(&t2, NULL, range_sum, &r2);

    pthread_join(t2, (void **)&res2); // waits for t2 thread (approx 5 secs)
    printf("t2 result = %d\n", *res2);
    free(res2);

    pthread_join(t1, (void **)&res1); // waits for t1 thread (approx 5 more secs)
    printf("t1 result = %d\n", *res1);
    free(res1);
    printf("bye!\n");
    return 0;
}

/*
pthread_join(tid, &ret);
    - pause the calling thread for the given thread (arg1 - tid).
    - and collect return value of the thread in arg2 (out param).
        - if arg2 is NULL, return value of thread is not collected.
    - thread return value is "void*", so we are collecting it in "void**" (arg2 type)

wait() syscall revision:
    - int s;
    - waitpid(child_pid, &s, NULL);
        - parent waits for given child and collect its exit status.
        - for any process, exit status is "int", so we are passing addr of int (arg2 type - int*)
*/