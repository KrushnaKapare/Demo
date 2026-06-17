#include<stdio.h>

int flag = 0;

int factorial(int num)
{
	int fact = 1;
	for(int i = 1 ; i <= num ; i++)
		fact = fact * i;

	return fact;
}

int division(int op1, int op2)
{
	int q = 0;
	if(op2 != 0)
		q = op1 / op2;
	else{
		printf("Divide by zero error\n");
		flag = 1;
	}
	return q;
}






