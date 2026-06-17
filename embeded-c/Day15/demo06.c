#include<stdio.h>

int sum(int, int);
int diff(int, int);
int product(int, int);
int quotient(int, int);


int main(void)
{
	//int (*arr[4])(int, int) = {sum, diff, product, quotient};

	int (*arr[4])(int, int);

	arr[0] = sum;
	arr[1] = diff;
	arr[2] = product;
	arr[3] = quotient;

	printf("sum = %d\n", arr[0](100, 200));
	printf("diff = %d\n", arr[1](100, 200));
	printf("product = %d\n", arr[2](100, 200));
	printf("quotient = %d\n", arr[3](100, 200));


	return 0;
}

int sum(int num1, int num2)
{
	return num1 + num2;
}

int diff(int num1, int num2)
{
	return num1 - num2;
}

int product(int num1, int num2)
{
	return num1 * num2;
}

int quotient(int num1, int num2)
{
	return num1 / num2;
}



















