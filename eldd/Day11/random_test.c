#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*
int main()
{
    int num = rand();
    printf("pseudo random number: %d\n", num);
    return 0;
}
*/
int main()
{
    int fd = open("/dev/random", O_RDONLY);
    int num = 0;
    read(fd, &num, sizeof(num));
    printf("random number: %d\n", num);
    close(fd);
    return 0;
}