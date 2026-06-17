#include<stdio.h>

int factorial(int n)
{
	int fact = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		fact *= i;
	}

	return fact;
}


int main(void)
{
	int num;

	printf("Enter number : ");
	scanf("%d", &num);

	int f = factorial(num);
	printf("%d! = %d\n", num, f);

	return 0;
}




















