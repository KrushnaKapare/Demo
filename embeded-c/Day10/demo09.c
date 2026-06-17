#include<stdio.h>

int main(void)
{
	int num = 11;
	// num is an integer variable

	int *pnum = &num;
	// pnum is a pointer variable

	int **ppnum = &pnum;
	// ppnum is a pointer to pointer variable

	printf("&num = %u\n", &num);

	printf("pnum = %u\n", pnum);
	printf("&pnum = %u\n", &pnum);

	printf("ppnum = %u\n", ppnum);

	printf("num = %d\n", num);
	printf("*pnum = %d\n", *pnum);
	printf("*ppnum = %u\n", *ppnum);
	printf("**ppnum = %d\n", **ppnum);

	printf("sizeof(ppnum) = %d\n", sizeof(ppnum));

	return 0;
}




















