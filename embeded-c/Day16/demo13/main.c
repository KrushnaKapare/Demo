#include<stdio.h>
#include"mmath.h"

extern int flag;

int main(void)
{
	printf("5! = %d\n", factorial(5));
	
	int num1, num2;

	printf("Enter num1 and num2 : ");
	scanf("%d %d", &num1, &num2);

	int res = division(num1, num2);

	if(flag == 0)
		printf("%d / %d = %d\n", num1, num2, res);

	return 0;
}






