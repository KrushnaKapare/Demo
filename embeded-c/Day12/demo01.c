#include<stdio.h>

int main(void)
{
	//const int num = 11;
	int const num = 11;

	printf("num = %d\n", num);

	//num = 22;

	printf("num = %d\n", num);

	int *ptr = &num;

	printf("*ptr = %d\n", *ptr);

	*ptr = 22;

	printf("num = %d\n", num);
	return 0;
}




















