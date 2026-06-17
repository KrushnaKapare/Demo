#include<stdio.h>

int main(void)
{
	int num1 = 11, num2 = 22, num3 = 33;

	//int *arr[3] = {&num1, &num2, &num3};

	int *arr[3];

	arr[0] = &num1;
	arr[1] = &num2;
	arr[2] = &num3;

	// arr is an array of 3 int pointers

	printf("Addresses : %u %u %u\n", &num1, &num2, &num3);

	printf("arr = %u\n", arr);

	printf("arr[0] = %u\n", arr[0]);
	printf("arr[1] = %u\n", arr[1]);
	printf("arr[2] = %u\n", arr[2]);

	printf("Values : ");
	for(int i = 0 ; i < 3 ; i++)
		printf("%-4d", *arr[i]);
	printf("\n");

	return 0;
}




















