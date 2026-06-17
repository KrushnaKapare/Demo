#include<stdio.h>

#define SIZE 7
#define PI 3.142

const float pi = 3.142;


void accept_array(int arr[]);
void print_array(int arr[]);

int main(void)
{
	int arr[SIZE];

	accept_array(arr);
	print_array(arr);

	return 0;
}

void accept_array(int arr[])
{
	printf("Enter %d numbers : ", SIZE);
	for(int i = 0 ; i < SIZE ; i++)
		scanf("%d", &arr[i]);
}

void print_array(int arr[])
{
	printf("Array : ");
	for(int i = 0 ; i < SIZE ; i++)
		printf("%-4d", arr[i]);
	printf("\n");
}



















