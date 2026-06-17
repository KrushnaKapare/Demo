#include<stdio.h>

int main(void)
{
	unsigned char num1 = 0xAB, num2 = 0x34;

	printf("num1 = %X\nnum2 = %X\n", num1, num2);

	printf("num1 & num2 = %X\n", num1 & num2);
	printf("num1 | num2 = %X\n", num1 | num2);
	printf("num1 ^ num2 = %X\n", num1 ^ num2);
	printf("~num1 = %X\n", ~num1);
	printf("~num2 = %X\n", ~num2);

	return 0;
}




















