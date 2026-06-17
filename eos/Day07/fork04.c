#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	printf("Program started !!!\n");
	int ret = fork();
	if(ret == -1)
	{	
		printf("fork() is failed to create a child process \n");
		exit(ret);
	}
	else if(ret == 0)
	{
		// child process
		printf("child : pid = %d, ppid = %d\n", getpid(), getppid());
		printf("child : fork returned = %d\n", ret);
	}
	else
	{
		// parent process
		printf("parent : pid = %d, ppid = %d\n", getpid(), getppid());
		printf("parent : fork returned = %d\n", ret);
	}
	printf("Program fininshed !!!\n");
	return 0;
}





