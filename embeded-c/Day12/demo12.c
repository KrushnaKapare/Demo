#include<stdio.h>

int main(void)
{
	int arr[3][3];

	printf("Enter array elements : \n");
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			printf("Enter arr[%d][%d] : ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}

	printf("2D Array : \n");
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			printf("%-4d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}




















