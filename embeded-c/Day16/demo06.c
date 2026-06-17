#include<stdio.h>

#define SWAP(n1, n2, type)	{	type temp = n1;	\
								n1 = n2;	\
								n2 = temp;	\
							}

int main(void)
{
	int num1 = 10, num2 = 20;
	printf("Before swap : num1 = %d, num2 = %d\n", num1, num2);
	SWAP(num1, num2, int);
	printf("After swap : num1 = %d, num2 = %d\n", num1, num2);

	float var1 = 1.5f, var2 = 2.5f;
	printf("Before swap : var1 = %f, var2 = %f\n", var1, var2);
	SWAP(var1, var2, float);
	printf("After swap : var1 = %f, var2 = %f\n", var1, var2);



	return 0;
}




















