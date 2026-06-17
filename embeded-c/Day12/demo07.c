#include<stdio.h>
#include<stdlib.h>

// void *malloc(size_t size);
//	size - total size to be allocated in bytes
//	returns starting address of allocated space
//		allocated space contains garbage

// void free(void *ptr);
//		ptr - starting address of the space to be released/free


void accept_array(int arr[], size_t length);
void print_array(int arr[], size_t length);

int main(void)
{
	int length;
	
	//1. take length of array from user
	printf("Enter array length : ");
	scanf("%d", &length);
	
	//2. allocating space to an array at runtime
	int *ptr = (int *)malloc(length * sizeof(int));

	//3. use allocated space of the array
	accept_array(ptr, length);
	print_array(ptr, length);

	//4. release allocated space
	free(ptr);

	return 0;
}

void accept_array(int arr[], size_t length)
{
	printf("Enter %d array elements : ", length);
	for(int i = 0 ; i < length ; i++)
		scanf("%d", &arr[i]);
}
void print_array(int arr[], size_t length)
{
	printf("Array : ");
	for(int i = 0 ; i < length ; i++)
		printf("%-4d", arr[i]);
	printf("\n");
}



















