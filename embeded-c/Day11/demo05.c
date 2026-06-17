#include<stdio.h>

int main(void)
{
	int arr[5] = {11, 22, 33, 44, 55};

	// arr 	- indicates starting address of the array
	//		- base address of the array
	//		- address of 0th index element of the array

	printf("arr = %u\n", arr);
	printf("&arr[0] = %u\n", &arr[0]);

	int *ptr = arr;
	printf("ptr = %u\n", ptr);

	printf("Array : \n");
	for(int i = 0 ; i < 5 ; i++)
		printf("ptr[%d] = %d\n", i, ptr[i]);

	return 0;
}




















