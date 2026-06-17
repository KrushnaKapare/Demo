#include<stdio.h>

// bit fields
//	- can be used in structure variables only
//	- memory will be allocated in number of bits for structure members
//	- can be used only with integer datatypes	(char, short, int, long)
//	- can be used with signed and unsigned
//	- can not be used with float, double, pointers, user defined datatypes
//	- can not create array of bit fields
//	- can not use '&' operator on bit fields
struct date{
	unsigned int dd	: 5;
	unsigned int mm : 4;
	unsigned int yyyy : 16;
};

// dd		:	1 - 31(11111)	- 5 bits	- 32 bits	- 27 bits			
// mm		:	1 - 12(1100)	- 4 bits	- 32 bits	- 28 bits
// yyyy		:	0000 - 9999 	- 16 bits	- 32 bits	- 16 bits


int main(void)
{
	struct date d = {5, 9, 2025};

	printf("sizeof(struct date) : %d\n", sizeof(struct date));

	printf("Today's date : %u / %u / %u\n", d.dd, d.mm, d.yyyy);

	return 0;
}




















