#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void)
{
	int ret, s;
	printf("Parent : Program started !!!\n");
	for(int i = 0 ; i < 5 ; i++)
	{
		ret = fork();
		if(ret == 0)
		{
			printf("Inside chile : %d ( %d )\n", getpid(), getppid());
			sleep(5);
			exit(0);
		}
	}
	printf("Parent : All 5 childs are created !!!\n");
	
	for(int i = 0 ; i < 5 ; i++)
	{
		ret = wait(&s);
		printf("Parent : Exit status of child %d = %d\n", ret, WEXITSTATUS(s));
	}
	printf("Parent : program finished !!!\n");
	return 0;
}







