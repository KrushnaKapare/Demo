#include<stdio.h>

int main(void)
{
	int arr[5] = {11, 22, 33, 44, 55};

	// arr - base address of the array (address of first element)
	// &arr - address of the array (address of whole array)

	printf("arr = %u\n", arr);
	printf("&arr = %u\n", &arr);

	int *ptr1 = arr;
	
	int (*ptr2)[5] = &arr;

	printf("*ptr1 = %d\n", *ptr1);
	printf("*ptr2 = %u\n", *ptr2);

	printf("ptr1 + 1 = %u\n", ptr1 + 1);
	printf("ptr2 + 1 = %u\n", ptr2 + 1);

	return 0;
}




















