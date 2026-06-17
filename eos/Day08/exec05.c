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
		char *argv[] = {"env.out", NULL};
		char *envp[] = {"MYUSERNAME=sunbeam", "MYHOME=/home/sunbeam", "MYPWD=Day08", NULL};
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





