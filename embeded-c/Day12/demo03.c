#include<stdio.h>

int main(void)
{
	int num1 = 11;
	int num2 = 22;

	int * const ptr = &num1;
	// ptr is constant pointer to integer

	printf("num1 = %d\n", *ptr);

	*ptr = 111;

	ptr = &num2;

	printf("num2 = %d\n", *ptr);

	*ptr = 222;

	printf("num1 = %d, num2 = %d\n", num1, num2);

	return 0;
}




















