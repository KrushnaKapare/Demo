#include<stdio.h>
#include<stdlib.h>


void accept_array(int **ptr, int row, int col);
void print_array(int **ptr, int row, int col);


int main(void)
{
	//1. Allocate memory at runtime
	int row, col;
	
	printf("Enter row and col : ");
	scanf("%d %d", &row, &col);

	int **ptr = (int **)malloc(row * sizeof(int *));
	for(int i = 0 ; i < row ; i++)
		ptr[i] = (int *)malloc(col * sizeof(int));

	//2. use array
	accept_array(ptr, row, col);
	print_array(ptr, row, col);

	//3. release the array
	for(int i = 0 ; i < row ; i++)
		free(ptr[i]);
	free(ptr);	

	return 0;
}

void accept_array(int **ptr, int row, int col)
{
	printf("Enter 2D array : \n");
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("Enter ptr[%d][%d] : ", i, j);
			scanf("%d", &ptr[i][j]);
		}
	}
}

void print_array(int **ptr, int row, int col)
{
	printf("2D array : \n");
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("%-4d", ptr[i][j]);		// *(*(ptr + i) + j)
		}
		printf("\n");
	}
}



















