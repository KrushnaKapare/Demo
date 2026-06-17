#include<stdio.h>

// array notation
//void print_array(int ptr[]);

// pointer notation
void print_array(int *ptr)
{
	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", i[ptr]);
	printf("\n");
}

void accept_array(int *ptr)
{
	printf("Enter Array elements : ");
	for(int i = 0 ; i < 5 ; i++)
		scanf("%d", ptr + i);
}


int main(void)
{
	int arr[5] = {11, 22, 33, 44, 55};

	printf("arr + 0 = %u\n", arr + 0);
	printf("arr + 1 = %u\n", arr + 1);
	printf("arr + 2 = %u\n", arr + 2);
	printf("arr + 3 = %u\n", arr + 3);
	printf("arr + 4 = %u\n", arr + 4);

	printf("*(arr + 0) = %u\n", *(arr + 0));
	printf("*(arr + 1) = %u\n", *(arr + 1));
	printf("*(arr + 2) = %u\n", *(arr + 2));
	printf("*(arr + 3) = %u\n", *(arr + 3));
	printf("*(arr + 4) = %u\n", *(arr + 4));
	
	print_array(arr);

	return 0;
}




















