#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(void)
{
	int s;
	int pid = fork();
	if(pid == 0)
	{
		// child process
		printf("Child : Table : ");
		for(int i = 1 ; i <= 10 ; i++)
		{
			printf("Child : %d\n", i * 10);
			sleep(1);
		}
		_exit(0);
	}
	else
	{
		// parent process
		waitpid(pid, &s, 0);
		printf("Parent : Exit status : %d\n", WEXITSTATUS(s));
	}
	printf("Parent : Program finished\n");
	return 0;
}



