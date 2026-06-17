#include<stdio.h>

#define SIZE 10

int main(void)
{
	printf("SIZE = %d\n", SIZE);

//#undef SIZE

#ifndef SIZE
#define SIZE 100
#endif

	printf("SIZE = %d\n", SIZE);
	return 0;
}




















