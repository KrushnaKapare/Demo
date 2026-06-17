#include<stdio.h>

int main(void)
{
	//char *ptr1 = 100;
	// SF(ptr1) = 1 byte

	int *ptr1 = 100;
	// SF(ptr1) = 4 byte
	
	printf("ptr1 = %u\n", ptr1);
	printf("ptr1 + 1 = %u\n", ptr1 + 1);	// ptr1 + SF(ptr1) = 100 + 4 = 104
	printf("ptr1 - 1 = %u\n", ptr1 - 1);	// ptr1 - SF(ptr1) = 100 - 4 = 96

	printf("ptr1 + 2 = %u\n", ptr1 + 2);	// ptr1 + 2 * SF(ptr1) = 100 + 2 * 4 = 108
	printf("ptr1 - 2 = %u\n", ptr1 - 2);	// ptr1 - 2 * SF(ptr1) = 100 - 2 * 4 = 92
	
	return 0;
}




















