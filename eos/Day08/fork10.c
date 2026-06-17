#include<stdio.h>
#include<unistd.h>

int main(void)
{
	//		|
	printf("Program started !!!\n");
	fork();
	//		|	|
	printf("After fork1 : pid = %d, ppid = %d\n", getpid(), getppid());
	fork();
	//		|	|	|	|
	printf("After fork2 : pid = %d, ppid = %d\n", getpid(), getppid());
	printf("program finished !!!\n");
	return 0;
}
