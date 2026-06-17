#include<stdio.h>

#define SIZE 10

int main(void)
{
	printf("SIZE = %d\n", SIZE);

#undef SIZE
#define SIZE 100
	
	printf("SIZE = %d\n", SIZE);

	return 0;
}




















