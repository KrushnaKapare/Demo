#include<stdio.h>

// Compile program as
//		gcc demo10.c -DVERSION=1
//	or
//		gcc demo10.c -D'SQR(n)=(n)*(n)'
//	or
//		gcc demo10.c -D'SQR(n)=(n)*(n)' -DVERSION=2


int main(void)
{
	printf("5^2 = %d\n", SQR(5));

#if VERSION == 1
	printf("This is version 1\n");
#elif VERSION == 2
	printf("This is version 2\n");
#else
	printf("This is last version\n");
#endif

	return 0;
}




















