#include<stdio.h>

int main(void)
{
	int arr[5];

	printf("Enter array elements : ");
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", arr[i]);
	printf("\n");
	
	printf("sizeof(arr) = %d\n", sizeof(arr));

	return 0;
}




















