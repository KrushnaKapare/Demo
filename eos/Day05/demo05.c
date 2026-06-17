
// File IO system call

// int open(const char *pathname, int flags, mode_t mode);
//	arg1 - file path
//	arg2 - O_CREAT, O_RDONLY, O_WRONLY, O_RDWR, O_TRUNC, O_APPEND
//	arg3 - mode is optional, can be used only when using O_CREAT
//	returns - on success returns file descriptor (non negative number)
//			  on error returns -1

//	w - O_WRONLY | O_TRUNC | O_CREAT
//	r - O_RDONLY
//	a - O_WRONLY | O_APPEND | O_CREAT

//	w+ - O_RDWR | O_TRUNC | O_CREAT
// 	r+ - O_RDWR | O_TRUNC
//	a+ - O_RDWR | O_APPEND | O_CREAT

// ssize_t read(int fd, void *buf, size_t count)
//	arg1 - file descriptor
//	arg2 - address of buffer in memory
//	arg3 - size of buffer
//	returns - number of bytes read
//			  0 if EOF is reached
//			  -1 on error

// ssize_t write(int fd, const void *buf, size_t count)
//	arg1 - file descriptor
//	arg2 - address of buffer in memory
//	arg3 - size of buffer
//	returns - number of bytes written
//			  -1 on error

// int close(int fd);
//	arg1 - file descriptor
//	returns - 0 on success or -1 on failure

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	char *srcpath, *destpath;
	char buf[32];
	int cnt;

	if(argc != 3)
	{
		printf("Source and destination filepaths are not mentioned\n");
		printf("Run as : %s <src filepath> <dest filepath>\n", argv[0]);
		exit(1);
	}

	srcpath = argv[1];
	destpath = argv[2];

	//1. open src file in read mode and dest file in write mode
	int fd_s = open(srcpath, O_RDONLY);
	//	err check
	int fd_d = open(destpath, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	// 	err check
	
	//2. read from src file and write into dest file
	while((cnt = read(fd_s, buf, sizeof(buf))) > 0)
		write(fd_d, buf, cnt);

	//3. close both the file descriptors
	close(fd_s);
	close(fd_d);

	printf("File is copied successfully !!!\n");
	
	return 0;
}












