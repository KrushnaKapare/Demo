#include<stdio.h>

void accept_array(int ptr[]);
void print_array(int ptr[]);


int main(void)
{
	int arr[5];

	accept_array(arr);
	print_array(arr);

	return 0;
}

void accept_array(int ptr[])
{
	printf("Enter array elements : ");
	for(int i = 0 ; i < 5 ; i++)
		scanf("%d", &ptr[i]);
}

void print_array(int ptr[])
{
	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", ptr[i]);
	printf("\n");
}



















