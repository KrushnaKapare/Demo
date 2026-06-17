#include<stdio.h>

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//	ptr - address where wants to store after read
//	size - size of individual record
//	nmemb - no of records
//	stream - FILE *
//	returns no of records read from file

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//	ptr - address from where wants to write into file
//	size - size of individual record
//	nmemb - no of records
//	stream - FILE *
//	returns no of records wrtitten into file

int main(void)
{
	int arr[5];

	//1. open file in read mode
	FILE *fp = fopen("file4.txt", "rb");

	//2. read array from file
	fread(arr, sizeof(int), 5, fp);

	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", arr[i]);
	printf("\n");

	//3. close file
	fclose(fp);

	return 0;
}




















