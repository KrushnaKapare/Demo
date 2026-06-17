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
	int arr[5] = {11, 22, 33, 44, 55};

	//1. open file in write mode
	FILE *fp = fopen("file4.txt", "wb");

	//2. write array into file
	fwrite(arr, sizeof(int), 5, fp);

	//3. close file
	fclose(fp);

	printf("Array is written into file !!!\n");
	return 0;
}




















