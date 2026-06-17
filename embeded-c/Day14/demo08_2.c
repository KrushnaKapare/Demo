#include<stdio.h>

// int fgetc(FILE *stream)
//		stream - FILE *
//		returns character read

int main(void)
{
	//1. open file in read mode
	FILE *fp = fopen("file1.txt", "r");

	//2. read characters one by one from file
	char ch;

	printf("File content : \n");
	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);
	
	printf("\n");

	//3. close the file
	fclose(fp);

	return 0;
}




















