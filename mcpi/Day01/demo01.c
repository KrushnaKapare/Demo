#include<stdio.h>

void print_binary(unsigned short num)
{
	unsigned short mask = 0x8000;
	//	1000 0000 0000 0000
	printf("%hu : ", num);
	while(mask)
	{
		if(num & mask)
			printf("1");
		else
			printf("0");
		mask = mask >> 1;
	}
	printf("\n");
}


int main(void)
{
	unsigned short num;

	printf("Enter number : ");
	scanf("%hu", &num);

	print_binary(num);

	return 0;
}




