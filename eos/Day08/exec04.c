#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(void)
{
	int s;
	int pid = fork();
	if(pid == 0)
	{
		// child process
		char *argv[] = {"ls", "-l", "-i", "-a", "-h", NULL};
		int ret = execve("/usr/bin/ls", argv, NULL);
		if(ret == -1)
		{
			perror("exec() failed");
			_exit(ret);
		}
	}
	else
	{
		// parent process
		waitpid(-1, &s, 0);
	}
	printf("Program finished\n");
	return 0;
}





