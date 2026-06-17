#include<stdio.h>

#pragma pack(1)

struct test{
	unsigned int a : 3;
	unsigned int b : 5;
};

int main(void)
{
	struct test t;

	char *ptr = (char *)&t;

	*ptr = 0xAB;
	
	//	10101011
	//	a = 3	- 011
	//	b = 21	- 10101
	
	printf("*ptr = %X\n", *ptr);
	printf("a = %u\n", t.a);
	printf("b = %u\n", t.b);

	printf("sizeof(struct test) : %d\n", sizeof(struct test));
	return 0;
}




















