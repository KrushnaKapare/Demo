#include <stdio.h>
#include <unistd.h>

int main() 
{
	int pid;
	pid = fork();
	if(pid == 0)
		printf("child running!\n");
	else
		printf("parent running!\n");
	return 0;
}

