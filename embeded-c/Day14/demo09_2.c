#include<stdio.h>

// char *fgets(char *s, int size, FILE *stream);
//		s - address of string where to data to be stored after reading
//		size - length of array
//		stream - FILE *
//		returns - address of same array on success and NULL on EOF or error


int main(void)
{
	char str[5]; 
	
	//1. open file into read mode
	FILE *fp = fopen("file2.txt", "r");

	//2. read strings from file
	printf("File content : \n");
	
	while(fgets(str, sizeof(str), fp) != NULL)
		printf("%s", str);

	printf("\n");

	//3. close the file
	fclose(fp);

	return 0;
}




















