#include<stdio.h>

int num1 = 10, num2 = 20;

void swap(void)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void)
{
	printf("Before swap : num1 = %d, num2 = %d\n", num1, num2);
	
	swap();

	printf("After swap : num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}




















