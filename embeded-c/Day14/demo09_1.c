#include<stdio.h>

// int fputs(const char *s, FILE *stream);
//		s - address of a string
//		stream - FILE *
//		returns on negetive on success and EOF on error

int main(void)
{
	char *str[] = {"desd", "ditiss", "dmc", "dbda", "dac"}; 
	
	//1. open file into write mode
	FILE *fp = fopen("file2.txt", "w");

	//2. write strings into file
	for(int i = 0 ; i < 5 ; i++)
		fputs(str[i], fp);

	//	fputs(str[i], fp);		// &*(str + i) = str + i

	//3. close the file
	fclose(fp);

	printf("Strings are written into file !!!\n");
	return 0;
}




















