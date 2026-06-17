#include<stdio.h>

// op1 and op2 - input parameters
// pdiff - output parameter

int calculate(int op1, int op2, int *pdiff)
{
	*pdiff = op1 - op2;
	return op1 + op2;
	//return op1 - op2; 
}

int main(void)
{
	int num1 = 10, num2 = 20;
	int sum, diff;

	sum = calculate(num1, num2, &diff);

	printf("%d + %d = %d\n", num1, num2, sum);
	printf("%d - %d = %d\n", num1, num2, diff);
	
	return 0;
}




















