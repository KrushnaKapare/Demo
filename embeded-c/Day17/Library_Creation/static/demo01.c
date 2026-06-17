#include<stdio.h>
#include"mymath.h"

void print(int num)
{
	printf("print :: num = %d\n", num);
}


int main(void)
{
	int n1 = 10;
	int num;

	printf("Enter number : ");
	scanf("%d", &num);

	print(num);

	printf("%d! = %d\n", num, factorial(num));
	printf("2^3 = %d\n", mypower(2, 3));

	return 0;
}
























