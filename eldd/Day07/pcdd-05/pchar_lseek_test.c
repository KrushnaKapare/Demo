#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd, ret;
    char buf1[35] = "", buf2[32] = "";
    off_t pos;
    // open device file for rd-wr
    fd = open("/dev/pchar0", O_RDWR);
    if (fd < 0)
    {
        perror("failed to open device");
        _exit(1);
    }
    printf("device file opened.\n");
    // write (32 bytes) in device file
    strcpy(buf1, "012345ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ret = write(fd, buf1, strlen(buf1)); // returns 26
    printf("Wr - bytes written in device: %d\n", ret);
    // print cur file pos
    pos = lseek(fd, 0, SEEK_CUR);
    printf("cur pos = %ld\n", pos); // 32
    // take file pos at start
    lseek(fd, 0, SEEK_SET);
    memset(buf2, 0, sizeof(buf2));
    ret = read(fd, buf2, 6);
    printf("Rd - bytes read: %d - %s\n", ret, buf2); // 012345
    // print cur file pos
    pos = lseek(fd, 0, SEEK_CUR);
    printf("cur pos = %ld\n", pos); // 6
    // change file pos to end of file - 3 bytes
    lseek(fd, -3, SEEK_END);
    memset(buf2, 0, sizeof(buf2));
    ret = read(fd, buf2, 3);
    printf("Rd - bytes read: %d - %s\n", ret, buf2); // XYZ
    // close device file
    close(fd);
    printf("device file closed.\n");
    return 0;
}

// cmd> gcc pchar_lseek_test.c -o pchar_lseek_test.out
// cmd> sudo insmod pchar.ko     # if driver is not already loaded
// cmd> sudo ./pchar_lseek_test.out
// cmd> sudo dmesg | tail 20
// cmd> sudo rmmod pchar
