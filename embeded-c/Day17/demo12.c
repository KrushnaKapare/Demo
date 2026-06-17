#include<stdio.h>

int main(void)
{
	int num;

	printf("Enter number : ");
	scanf("%d", &num);

	if(num & 1)
		printf("%d number is odd\n", num);
	else
		printf("%d number is even\n", num);

	return 0;
}




















