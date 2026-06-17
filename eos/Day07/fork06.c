#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int i;
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
		for(i = 15 ; i > 0 ; i--)
		{
			printf("child : i = %d\n", i);
			sleep(1);
		}
	}
	else
	{
		// parent process
		for(i = 1 ; i <= 15 ; i++)
		{
			printf("parent : i = %d\n", i);
			sleep(1);
		}
	}
	printf("Program fininshed !!!\n");
	return 0;
}





