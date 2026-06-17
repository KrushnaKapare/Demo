#include<stdio.h>

int main(void)
{
	int num;

	printf("Enter number : ");
	scanf("%d", &num);

	if(num & 1)
		printf("%d number is not divisible by 2\n", num);
	else
		printf("%d number is divisible by 2\n", num);

	return 0;
}




















