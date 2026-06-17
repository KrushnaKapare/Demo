#include<stdio.h>

int main(void)
{
	int num = 11;
	char ch = 'A';
	double d = 3.142;

	void *ptr = NULL;


	ptr = &num;
	printf("num = %d\n", *(int *)ptr);

	ptr = &ch;
	printf("ch = %c\n", *(char *)ptr);

	ptr = &d;
	printf("d = %lf\n", *(double *)ptr);

	double *pd = ptr;
	printf("d = %lf\n", *pd);

	int *pn = ptr;
	printf("*pn = %d\n", *pn);

	return 0;
}




















