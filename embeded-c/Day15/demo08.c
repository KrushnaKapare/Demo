#include<stdio.h>

int sum(int, int);
int diff(int, int);
int product(int, int);
int quotient(int, int);

// pointer declaration
typedef int (*ptr)(int, int);
	// ptr - pointer

// type declaration
typedef int (ptr_t)(int, int);
	// ptr_t - data type

int main(void)
{
	
	ptr_t *ptr1 = sum;
	ptr_t *ptr2 = diff;
	ptr_t *ptr3 = product;
	ptr_t *ptr4 = quotient;
	
	printf("sum = %d\n", ptr1(100, 200));
	printf("diff = %d\n", ptr2(100, 200));
	printf("product = %d\n", ptr3(100, 200));
	printf("quotient = %d\n", ptr4(100, 200));

	ptr_t *arr[4] = {sum, diff, product, quotient};

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



















