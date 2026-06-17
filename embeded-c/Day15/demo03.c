#include<stdio.h>

// Function declaration
//		<return type> <function name>([List of types of arguments);

// Function pointer declaration
//		<return type> (*<function name>)([List of types of arguments);

//e.g.		void fun(void);
//			void (*ptr)(void);

// void *ptr(void);
//	ptr is a function with no arguments and which returns void *

void fun(void)
{
	printf("Lets have fun\n");
}

int main(void)
{
	// address of first instruction is nothing but address of function
	// function name indicates address of function

	printf("address of fun = %u\n", fun);

	void (*fptr)(void) = fun;

	printf("fptr = %u\n", fptr);

	// function with call with function name
	//		<function name>([list of actual arguments]);
	fun();

	// function with call with function pointer
	//		<function pointer name>([list of actual arguments]);
	fptr();


	return 0;
}




















