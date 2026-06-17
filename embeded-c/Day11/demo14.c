#include<stdio.h>
#include<string.h>

// strcmp()
//	arg1 - base address of first string
//	arg2 - base address of second string
//	returns		< 0	- string1 is less than string2		(-1)
//				= 0 - string1 and string2 are equal		(0)
//				> 0 - string1 is greater than string2	(+1)


int main(void)
{
	char str1[20], str2[20];

	printf("Enter str1 : ");
	scanf("%s", str1);
	printf("Enter str2 : ");
	scanf("%s", str2);

	int ret = strcmp(str1, str2);
	printf("ret = %d\n", ret);

	if(ret == 0)
		printf("strings are equal\n");
	else if(ret < 0)
		printf("str1 is less than str2\n");
	else
		printf("str1 is greater than str2\n");
	
	return 0;
}




















