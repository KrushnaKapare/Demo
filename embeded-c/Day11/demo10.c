#include<stdio.h>

int main(void)
{
	char str[20];

	printf("Enter string : ");
	//scanf("%s", str);			// only one word will be taken
	//scanf("%[^\n]s", str);		// accept upto '\n'
	scanf("%[^.]s", str);		// accept upto '.'

	printf("str = %s\n", str);

	return 0;
}




















