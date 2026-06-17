#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int argc, char *argv[], char *envp[])
{
	int s;
	int pid = fork();
	if(pid == 0)
	{
		// child process
		char *argv[] = {"env.out", NULL};
		int ret = execve("./env.out", argv, envp);
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





