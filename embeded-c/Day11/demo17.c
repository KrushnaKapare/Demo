#include<stdio.h>
#include<string.h>

// strtok()
//	arg1 - base address of string
//	arg2 - delimiters
//	returns address of next token

int main(void)
{
	char str[32] = "desd dmc ditiss desd dmc";

	char *ptr = strtok(str, " ");
	printf("ptr = %s\n", ptr);

	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	return 0;
}




















