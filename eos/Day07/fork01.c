#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("Program started !!!\n");
	fork();
	printf("Program fininshed !!!\n");
	return 0;
}
