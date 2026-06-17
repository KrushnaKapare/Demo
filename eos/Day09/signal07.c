#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

// step 1 : implement signal handler
void sigint_handler(int sig)
{
	printf("Signal caught : %d\n", sig);
}

int main(void)
{
	int i;
	struct sigaction sa;
	
	// step 2 : register signal handler
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	sigaction(SIGINT, &sa, NULL);

	while(1)
	{
		printf("running : %d\n", i);
		i++;
		sleep(2);
	}
	
	return 0;
}









