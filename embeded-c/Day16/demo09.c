#include<stdio.h>

#define VERSION	2

int main(void)
{
#if VERSION == 1
	printf("This is version 1\n");
#elif VERSION == 2
	printf("This is version 2\n");
#endif
	return 0;
}




















