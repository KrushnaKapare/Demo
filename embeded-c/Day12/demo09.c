#include<stdio.h>
#include<stdlib.h>

// void *realloc(void *ptr, size_t size);
//		ptr - starting address of a space to be resized
//		size - new size to which existing space to be resized
//		returns starting address of new allocated space

//	new size < old size	- (shrink)
//		existing space is shrinked to new size and 
//			same starting address will be returned	

// 	new size > old size - (grow)
//		1. immediate free space is avialable
//			existing space is resized to new size and 
//				same starting address is returned
//		2. immediate free space is not avialable
//			new space is created, existing data is copied from old space
//				to new space, release the old space and 
//				starting address of new space is returned



int main(void)
{
	char *ptr = malloc(8 * sizeof(char));

	for(int i = 0 ; i < 8 ; i++)
		ptr[i] = 'A' + i;

	printf("Array : ");
	for(int i = 0 ; i < 8 ; i++)
		printf("%c", ptr[i]);
	printf("\n");

//	ptr = realloc(ptr, 10);

//	ptr[9] = '#';
//	ptr[8] = '#';

	ptr = realloc(ptr, 6);

	printf("Array : ");
	for(int i = 0 ; i < 6 ; i++)
		printf("%c", ptr[i]);
	printf("\n");


	free(ptr);
	return 0;
}




















