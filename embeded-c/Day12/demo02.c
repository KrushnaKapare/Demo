#include<stdio.h>

int main(void)
{
	int num = 11;

	//const int *ptr = &num;
	int const *ptr = &num;
	// ptr is a pointer to constant integer
	printf("Before : num = %d\n", num);
	
	*ptr = 22;			// error

	printf("After : num = %d\n", num);

	ptr++;
	return 0;
}




















