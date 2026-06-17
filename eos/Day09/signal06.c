#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

// step 1 : implement SIGCHLD signal to avoid zombie process
void sigchld_handler(int sig)
{
	printf("Received SIGCHLD (%d) signal to process (%d)\n", sig, getpid());
	int s;
	wait(&s);
	printf("Exit status of child : %d\n", WEXITSTATUS(s));
}


int main(void)
{
	// step 2 : register/add SIGCHLD handler in process signal table
	signal(SIGCHLD, sigchld_handler);

	int pid = fork();
	if(pid == 0)
	{
		// child
		for(int i = 0 ; i < 5 ; i++)
		{
			printf("child (%d) : i = %d\n", getpid(), i);
			sleep(1);
		}
		_exit(0);
	}
	else
	{
		// parent
		for(int i = 0 ; i < 10 ; i++)
		{
			printf("parent (%d) : i = %d\n", getpid(), i);
			sleep(1);
			//if(i == 5)
			//	wait(&s);
		}
	}

	return 0;
}

















