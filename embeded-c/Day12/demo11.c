#include<stdio.h>

int main(void)
{
	int arr[3][4] = {1, 2, 3, 4, 10, 20, 30, 40, 11, 22, 33, 44};

	printf("2D Array :\n");
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			printf("%-4d", arr[i][j]);
		}
		printf("\n");
	}
	//	00	01	02	03
	//	10	11	12	13
	//	20	21	22	23

	return 0;
}




















