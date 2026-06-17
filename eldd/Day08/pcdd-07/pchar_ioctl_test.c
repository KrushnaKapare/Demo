#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "pchar_ioctl.h"

int main()
{
    int fd, ret;
    char buf1[32] = "", buf2[32] = "";
    struct fifo_info info;
    // open device file for rdwr
    fd = open("/dev/pchar0", O_RDWR);
    if (fd < 0)
    {
        perror("failed to open device");
        _exit(1);
    }
    printf("device file opened.\n");
    // write (26 bytes) in device file
    strcpy(buf1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ret = write(fd, buf1, strlen(buf1)); // returns 26
    printf("Wr 1- bytes written in device: %d\n", ret);
    // get info about device using ioctl.
    ret = ioctl(fd, FIFO_GET_INFO, &info);
    if (ret < 0)
    {
        perror("ioctl() failed");
        close(fd);
        _exit(1);
    }
    printf("FIFO state: size=%d, length=%d, avail=%d\n",
           info.size, info.length, info.avail);
    // write (4 bytes) in device file
    strcpy(buf1, "DESD");
    ret = write(fd, buf1, strlen(buf1));
    printf("Wr 2- bytes written in device: %d\n", ret); // returns 4
    // get info about device using ioctl.
    ret = ioctl(fd, FIFO_GET_INFO, &info);
    if (ret < 0)
    {
        perror("ioctl() failed");
        close(fd);
        _exit(1);
    }
    printf("FIFO state: size=%d, length=%d, avail=%d\n",
           info.size, info.length, info.avail);
    // read few bytes from device
    ret = read(fd, buf2, 6);
    printf("Rd-1 read %d bytes -- %s\n", ret, buf2);
    // get info about device using ioctl.
    ret = ioctl(fd, FIFO_GET_INFO, &info);
    if (ret < 0)
    {
        perror("ioctl() failed");
        close(fd);
        _exit(1);
    }
    printf("FIFO state: size=%d, length=%d, avail=%d\n",
           info.size, info.length, info.avail);
    // clear device
    ret = ioctl(fd, FIFO_CLEAR);
    if (ret < 0)
    {
        perror("ioctl() failed");
        close(fd);
        _exit(1);
    }
    printf("FIFO is cleared.\n");
    // get info about device using ioctl.
    ret = ioctl(fd, FIFO_GET_INFO, &info);
    if (ret < 0)
    {
        perror("ioctl() failed");
        close(fd);
        _exit(1);
    }
    printf("FIFO state: size=%d, length=%d, avail=%d\n",
           info.size, info.length, info.avail);
    // close device file
    close(fd);
    printf("device file closed.\n");
    return 0;
}

// cmd> gcc pchar_ioctl_test.c -o ioctl_test.out
// cmd> sudo insmod pchar.ko     # if driver is not already loaded
// cmd> sudo ./ioctl_test.out
// cmd> sudo dmesg | tail 20
// cmd> sudo rmmod pchar.ko
