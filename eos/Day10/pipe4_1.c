#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	// 1. open pipe file in write mode
	int fd = open("./myfifo", O_WRONLY);
	// err check

	//2. write data into pipe
	char str[20];
	printf("Enter string : ");
	scanf("%[^\n]s", str);
	write(fd, str, strlen(str));


	//3. close the file descriptor
	close(fd);

	return 0;
}









