#include<stdio.h>
#include<string.h>

// strlen()
//	arg1 - base address of string
//	returns length of given string

int main(void)
{
	char str[20];

	printf("Enter string : ");
	scanf("%[^\n]s", str);
	
	printf("str = %s\n", str);

	int len = strlen(str);
	printf("Length = %d\n", len);


	return 0;
}




















