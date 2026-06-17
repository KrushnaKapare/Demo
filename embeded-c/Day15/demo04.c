#include<stdio.h>

int addition(int, int);
void print_result(int);

int main(void)
{
	int (*ptr1)(int, int) = addition;
	// ptr1 is a pointer '*' to the collection '()' of instructions
	//	which takes two arguments of type integer '(int, int)'
	// and returns integer 'int'

	void (*ptr2)(int) = print_result;
	// ptr2 is a pointer '*' to the collection '()' of instructions
	//	which takes one arguments of type integer '(int)'
	// and returns nothing 'void'

	int num1, num2;

	printf("Enter two numbers : ");
	scanf("%d %d", &num1, &num2);

	int sum = ptr1(num1, num2);
	ptr2(sum);

	return 0;
}

int addition(int num1, int num2)
{
	return num1 + num2;
}

void print_result(int result)
{
	printf("Result = %d\n", result);
}


















