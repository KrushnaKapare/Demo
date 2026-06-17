#include<stdio.h>

int main(void)
{
	int num = 10;

	int const *ptr = &num;

	printf("Before : ptr = %u, *ptr = %d\n", ptr, *ptr);
	printf("num = %d\n", num);

	//*ptr++;
	//*++ptr;
	++*ptr;				// error

	printf("After : ptr = %u, *ptr = %d\n", ptr, *ptr);
	printf("num = %d\n", num);

	return 0;
}




















