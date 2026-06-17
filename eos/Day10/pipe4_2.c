#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	// 1. open pipe file in read mode
	int fd = open("./myfifo", O_RDONLY);
	// err check
	
	printf("waiting for msg ....\n");
	//2. write data into pipe
	char str[20];
	read(fd, str, sizeof(str));
	printf("Received data : %s\n", str);

	//3. close the file descriptor
	close(fd);

	return 0;
}









