#include<stdio.h>
#include<unistd.h>
#include<signal.h>

// step 1 : implement signal handler
void sigint_handler(int sig)
{
	printf("Signal caught in process (%d) : %d\n", getpid(), sig);
}

int main(void)
{
	int i;
	
	// step 2 : register signal handler
	signal(SIGINT, sigint_handler);

	while(1)
	{
		printf("running (%d) : %d\n", getpid(), i);
		i++;
		sleep(2);
	}
	
	return 0;
}









