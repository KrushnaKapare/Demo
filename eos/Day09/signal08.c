#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

// step 1 : implement signal handler
void sigint_handler(int sig, siginfo_t *info, void *ucontext)
{
	printf("Signal caught : %d\n", info->si_signo);
	printf("Sender process : %d\n", info->si_pid);
}

int main(void)
{
	int i;
	struct sigaction sa;
	
	// step 2 : register signal handler
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = sigint_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);

	while(1)
	{
		printf("running : %d\n", i);
		i++;
		sleep(2);
	}
	
	return 0;
}









