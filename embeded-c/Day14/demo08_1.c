#include<stdio.h>

// FILE *fopen(const char *pathname, const char *mode);
//	pathname - path of a file
//	mode - purpose	:	Text 	: r - read, w - write, a - append
//						Binary	: rb - read, wb - write, ab - append
//						r+, w+, a+
//						rb+, wb+, ab+
//	returns FILE * to the opened file

// int fclose(FILE *stream)
//		stream - FILE * returned by fopen
//		returns - 0 on success, EOF on failure

// int fputc(int c, FILE *stream)
//		c - character to be written
//		stream - FILE *
//		returns written character

int main(void)
{
	char str[128] = "I am doing PG Diploma in Embedded System Design";
	
	//1. open file in write mode
	FILE *fp = fopen("file1.txt", "w");

	//2. write characters one by one into file
	for(int i = 0 ; str[i] != '\0' ; i++)
		fputc(str[i], fp);

	//3. close the opened file
	fclose(fp);

	printf("Characters are written into file !!!\n");

	return 0;
}




















