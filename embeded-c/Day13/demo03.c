#include<stdio.h>

int main(void)
{
	int arr1[] = {1, 2, 3, 4};
	int arr2[] = {10, 20, 30, 40};
	int arr3[] = {11, 22, 33, 44};

	int *arr[3] = {arr1, arr2, arr3};

	printf("Base addresses : %u %u %u\n", arr1, arr2, arr3);
	
	printf("arr = %u\n", arr);
	printf("arr[0] = %u\n", arr[0]);
	printf("arr[1] = %u\n", arr[1]);
	printf("arr[2] = %u\n", arr[2]);

	printf("1st 1D array : ");
	for(int i = 0 ; i < 4 ; i++)
		printf("%-4d", arr[0][i]);
	printf("\n");

	printf("2nd 1D array : ");
	for(int i = 0 ; i < 4 ; i++)
		printf("%-4d", arr[1][i]);
	printf("\n");
	
	printf("3rd 1D array : ");
	for(int i = 0 ; i < 4 ; i++)
		printf("%-4d", arr[2][i]);
	printf("\n");

	printf("-------------------------\n");

	for(int i = 0 ; i < 3 ; i++)
	{
		printf("arr[%d] : ", i);
		for(int j = 0 ; j < 4 ; j++)
			printf("%-4d", arr[i][j]);
		printf("\n");
	}
	return 0;
}




















