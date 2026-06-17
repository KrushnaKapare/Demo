#include<stdio.h>

#define SQR(n)	(n) * (n)

int main(void)
{
	printf("5^2 = %d\n", SQR(5));
	
	int num = 5;
	printf("%d^2 = %d\n", num, SQR(num));

	printf("(3 + 2)^2 = %d\n", SQR(3 + 2));
	
	return 0;
}




















