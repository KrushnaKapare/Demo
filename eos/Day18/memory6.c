#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main()
{
    int fd, cnt;
    char *ptr;
    struct stat st;
    fd = open("hello.txt", O_RDONLY);
    fstat(fd, &st);
    ptr = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    write(1, ptr, st.st_size);
    getchar();
    close(fd);
    munmap(ptr, st.st_size);
    return 0;
}

// mapped segment
//    ptr = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

// anonymous segment -- not mapped to any file on disk
//    ptr = (char *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
