#include<stdio.h>

int main(void)
{
	unsigned char num1 = 0xAB;

	printf("unsigned : \n");
	printf("num1 << 2 : %X\n", num1 << 2);
	printf("num1 >> 2 : %X\n", num1 >> 2);

	signed char num2 = 0xAB;

	printf("signed : \n");
	printf("num2 << 2 : %X\n", num2 << 2);
	printf("num2 >> 2 : %X\n", num2 >> 2);
	return 0;
}




















