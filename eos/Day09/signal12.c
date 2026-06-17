#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void sig_handler(int sig)
{
	printf("Signal caught : %d [ Process ID = %d ]\n", sig, getpid());
}

int main(void)
{
	int i = 0;
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sig_handler;
	
	// register signal handler for SIGINT signal
	sigaction(SIGINT, &sa, NULL);
	
	// register signal handler for SIGTERM signal
	sigaction(SIGTERM, &sa, NULL);
	
	// wait till SIGTERM/SIGALRM/SIGSEGV is not received
	printf("waiting for any one signal ....\n");
	pause();
		// save signal mask of a process into temp variable
		// apply specified mask to process
		// block the calling process
		// wait for any one one signal to receive
		// after signal delivery set old mask agian back to process and return

	printf("bye\n");
	return 0;
}


















