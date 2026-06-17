#include<stdio.h>
#include<string.h>

// strstr()
//	arg1 - base address of string
//	arg2 - base address of sub string
//	returns address of located characted

int main(void)
{
	char str[32] = "desd dmc ditiss desd dmc";
	char sub[10];

	printf("str = %s\n", str);
	printf("Enter string : ");
	scanf("%s", sub);

	char *ptr = strstr(str, sub);
	
	printf("str = %u\n", str);
	printf("ptr = %u\n", ptr);

	return 0;
}




















