#include<stdio.h>

void print_binary(int num)
{
	if(num == 0)
		return;
	print_binary(num / 2);
	printf("%d", num % 2);
}


int main(void)
{
	int num;

	printf("Enter number : ");
	scanf("%d", &num);
	
	printf("%d : ", num);
	print_binary(num);
	printf("\n");
	return 0;
}




















