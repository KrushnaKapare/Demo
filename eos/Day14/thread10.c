#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m;
pthread_cond_t c;
int flag = 0; // "SUNBEAM" not printed

void *sunbeam(void *p)
{
    char *str = "SUNBEAM\n";
    pthread_mutex_lock(&m);
    for (int i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
        fflush(stdout);
        sleep(1);
    }
    flag = 1; // "SUNBEAM" is printed
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
    return NULL;
}

void *infotech(void *p)
{
    char *str = "INFOTECH\n";
    pthread_mutex_lock(&m);
    while (!flag)
        pthread_cond_wait(&c, &m);
    for (int i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
        fflush(stdout);
        sleep(1);
    }
    pthread_mutex_unlock(&m);
    return NULL;
}

int main()
{
    pthread_t st, it;
    int ret;
    pthread_mutex_init(&m, NULL);
    pthread_cond_init(&c, NULL);
    ret = pthread_create(&it, NULL, infotech, NULL);
    ret = pthread_create(&st, NULL, sunbeam, NULL);
    // main thread waits for both threads to complete -- one by one
    pthread_join(st, NULL);
    pthread_join(it, NULL);
    pthread_cond_destroy(&c);
    pthread_mutex_destroy(&m);
    return 0;
}
