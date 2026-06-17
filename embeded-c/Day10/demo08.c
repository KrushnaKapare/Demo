#include<stdio.h>

int main(void)
{
	int num = 11;
	char ch = 'A';
	double d = 3.142;

	int *pnum = &num;
	char *pch = &ch;
	double *pd = &d;

	printf("&num = %lu, pnum = %lu\n", &num, pnum);
	printf("&ch = %lu, pch = %lu\n", &ch, pch);
	printf("&d = %lu, pd = %lu\n", &d, pd);

	printf("num = %d\n", *pnum);
	printf("ch = %c\n", *pch);
	printf("d = %lf\n", *pd);

	printf("scale factor of int * = %d\n", sizeof(int));
	printf("scale factor of char * = %d\n", sizeof(char));
	printf("scale factor of double * = %d\n", sizeof(double));

	printf("sizeof(pnum) = %d\n", sizeof(pnum));
	printf("sizeof(pch) = %d\n", sizeof(pch));
	printf("sizeof(pd) = %d\n", sizeof(pd));

	return 0;
}




















