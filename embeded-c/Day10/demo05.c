#include<stdio.h>

/*
	Pointer
		- is a variable which stores address of another variable

		- addresses are always unsigned integers
		- type of pointer variable will be same as type of targeted variable
		- eg int num = 10;
				- pointer should be of type intger pointer
		- syntax:
			<data type> *<name of variable>;

		- eg int *ptr = &num;
		
		- two operators are always used with pointers
			- & : address of / reference operator
				- to get address of variable
				- eg. &num - will give you address of num

			- * : value at / de reference operator
				- to get the value of targeted variable
				- eg. *ptr - will give value of num
	

*/


int main(void)
{
	int num = 11;
	// num is an integer variable

	int *ptr = &num;
	// ptr is a pointer vaiable which stores address of integer variable

	printf("num = %d\n", num);
	printf("&num = %p\n", &num);

	printf("ptr = %p\n", ptr);
	printf("&ptr = %p\n", &ptr);
	printf("*ptr = %d\n", *ptr);

	*ptr = 22;
	printf("updated num = %d\n", num);

	return 0;
}




















