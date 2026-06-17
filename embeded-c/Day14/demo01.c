#include<stdio.h>

#pragma pack(1)

struct test{
	char ch;		// 1 byte
	int num;		// 4 bytes
	short sh;		// 2 bytes
};					// 7 bytes


int main(void)
{
	printf("sizeof(struct test) = %d\n", sizeof(struct test));
	return 0;
}




















