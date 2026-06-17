#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// thread to print table of given number.
void *print_table(void *param)
{
    int *ptr = (int *)param;
    int i, num = *ptr;
    for (i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", num, i, num * i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    int ret, num1 = 5, num2 = 7, num3 = 13;
    pthread_t t1, t2, t3;
    ret = pthread_create(&t1, NULL, print_table, &num1);
    ret = pthread_create(&t2, NULL, print_table, &num2);
    ret = pthread_create(&t3, NULL, print_table, &num3);
    printf("press enter to exit the main...\n");
    getchar();
    return 0;
}

/*
Thread termination:
1. Thread is auto terminated when thread function is completed.
2. Thread cancellation request can be sent to the thread explicitly using
    - pthread_cancel(tid);
3. Signal can be sent to the thread, so that signal handler is executed by the thread. However, signals are always send process-wide (common handler).
    - pthread_kill(tid, signum);
4. A thread can terminate itself (in thread function) using
    - pthread_exit(ret);
5. When a process is terminated, all threads in the process are terminated.

Main thread:
1. Created by default for each process.
2. When main thread is terminated, the process is terminated (in Linux).

Note:
- Each thread have its own stack.
- The function activation records of thread function (and functions called in it) are created on respective stack (calling thread).
- Thus local variables of thread function (e.g. num, ptr, ...) are kept on separate stack. There is no race condition.
*/
