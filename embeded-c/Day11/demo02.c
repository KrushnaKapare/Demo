#include<stdio.h>

int main(void)
{
	/*
	char *ptr1 = 200;
	char *ptr2 = 100;

	printf("ptr1 = %u\n", ptr1);
	printf("ptr2 = %u\n", ptr2);

	printf("ptr1 - ptr2 = %d\n", ptr1 - ptr2);
	*/

	int *ptr1 = 200;
	int *ptr2 = 100;

	printf("ptr1 = %u\n", ptr1);
	printf("ptr2 = %u\n", ptr2);

	printf("ptr1 - ptr2 = %d\n", ptr1 - ptr2);

	// ptr1 - ptr2
	//	= (ptr1 - ptr2) / SF(ptr1)
	//	= (200 - 100) / 4
	//	= 100 / 4
	//	= 25

	return 0;
}




















