#include<stdio.h>
#include<string.h>

// strcat()
//	arg1 - base address of destination string
//	arg2 - base address of source string
//	returns base address of destination string

int main(void)
{
	char str1[20] = "desd", str2[] = "sunbeam";

	printf("Before : str1 = %s, str2 = %s\n", str1, str2);
	
	strcat(str1, str2);

	printf("After : str1 = %s, str2 = %s\n", str1, str2);
	return 0;
}




















