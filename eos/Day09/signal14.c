#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

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
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	sigfillset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);

	i = 0;
	while(1)
	{
		printf("running : %d\n", i++);
		sleep(2);
	}
	
	return 0;
}









