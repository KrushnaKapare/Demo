#include<stdio.h>

int main(void)
{
	char str1[5] = {'d', 'e', 's', 'd'};
	char str2[] = {'d', 'e', 's', 'd'};
	
	char str3[5] = "desd";  
	char str4[] = "desd"; 		// by default '\0' is added at the end


	printf("sizeof(str1) = %d\n", sizeof(str1));
	printf("sizeof(str2) = %d\n", sizeof(str2));
	printf("sizeof(str3) = %d\n", sizeof(str3));
	printf("sizeof(str4) = %d\n", sizeof(str4));

	return 0;
}




















