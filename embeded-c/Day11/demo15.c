#include<stdio.h>

// strchr()
//	arg1 - base address of string
//	arg2 - ASCII value of character
//	returns address of located characted

int main(void)
{
	char str[20] = "desd dmc ditiss";
	char ch;

	printf("str = %s\n", str);
	printf("Enter chacter : ");
	scanf("%c", &ch);

	char *ptr = strchr(str, ch);
	
	printf("str = %u\n", str);
	printf("ptr = %u\n", ptr);

	return 0;
}




















