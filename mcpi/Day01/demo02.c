#include<stdio.h>

void print_binary(void *ptr, size_t size)
{
	for(int i = size - 1 ; i >= 0 ; i--)
	{
		unsigned char mask = 0x80;
		while(mask)
		{
			if(*((char *)ptr + i) & mask)
				printf("1");
			else
				printf("0");
			mask = mask >> 1; 
		}
		printf(" ");
	}
	printf("\n");
}

int main(void)
{
	char ch = 'A';

	printf("%c : ", ch);
	print_binary(&ch, sizeof(ch));

	short sh = 0xABCD;

	printf("%X : ", sh);
	print_binary(&sh, sizeof(sh));

	int num = 20;

	printf("%d : ", num);
	print_binary(&num, sizeof(num));

	return 0;
}







