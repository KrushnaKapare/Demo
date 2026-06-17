#include<stdio.h>


void swap(int *pnum1, int *pnum2)
{
	// num1 - *pnum1
	// num2 - *pnum2
	int temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;
}

int main(void)
{
	int num1 = 10, num2 = 20;
	
	printf("Before swap : num1 = %d, num2 = %d\n", num1, num2);
	
	swap(&num1, &num2);

	printf("After swap : num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}




















