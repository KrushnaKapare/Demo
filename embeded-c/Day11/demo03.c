#include<stdio.h>

int main(void)
{
	int arr[5] = {11, 22, 33, 44, 55};

	printf("0th index element = %d\n", arr[0]);
	printf("1st index element = %d\n", arr[1]);
	printf("2nd index element = %d\n", arr[2]);
	printf("3rd index element = %d\n", arr[3]);
	printf("4th index element = %d\n", arr[4]);

	arr[2] = 30;
	printf("arr[2] = %d\n", arr[2]);

	printf("Array : ");
	for(int index = 0 ; index < 5 ; index++)
		printf("%-4d", arr[index]);
	printf("\n");

	return 0;
}




















