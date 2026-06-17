#include<stdio.h>
#include<string.h>

// strcpy()
//	arg1 - base address of destination string
//	arg2 - base address of source string
//	returns base address of destination string


int main(void)
{
	char str1[20], str2[20];

	printf("Enter str1 : ");
	scanf("%s", str1);

	printf("str1 = %s\n", str1);

	strcpy(str2, str1);

	printf("str2 = %s\n", str2);

	return 0;
}




















