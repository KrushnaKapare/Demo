#include<stdio.h>

int main(void)
{
	int num = 0x41424344;

	char *ptr = (char *)&num;

	if(*ptr == 0x44)
		printf("Litte Endian\n");
	else
		printf("Big Endian\n");

	return 0;
}




















