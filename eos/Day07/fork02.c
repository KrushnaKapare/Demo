#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("Program started !!!\n");
	int ret = fork();
	printf("fork returned = %d\n", ret);
	printf("Program fininshed !!!\n");
	return 0;
}
