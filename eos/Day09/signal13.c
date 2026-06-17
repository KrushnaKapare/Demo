#include<stdio.h>
#include<unistd.h>
#include<signal.h>

// step 1 : implement signal handler
void sigint_handler(int sig)
{
	printf("Signal caught : %d [ Process ID = %d] \n", sig, getpid());
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("inside SIGINT handler : %d\n", i);
		sleep(2);
	}
}

int main(void)
{
	int i;
	
	// step 2 : register signal handler
	signal(SIGINT, sigint_handler);

	while(1);
	
	return 0;
}









