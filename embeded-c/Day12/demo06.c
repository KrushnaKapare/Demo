#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap_int(int *pnum1, int * pnum2)
{
	int temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;
}

void swap_char(char *pch1, char *pch2)
{
	char temp = *pch1;
	*pch1 = *pch2;
	*pch2 = temp;
}

void swap(void *p1, void *p2, size_t size)
{
	void *temp = malloc(size);
	memcpy(temp, p1, size);		//temp = *p1;
	memcpy(p1, p2, size);		//*p1 = *p2;
	memcpy(p2, temp, size);		//*p2 = temp;
	free(temp);
}

int main(void)
{
	int n1 = 10, n2 = 20;
	
	printf("Before : n1 = %d, n2 = %d\n", n1, n2);
	//swap_int(&n1, &n2);
	swap(&n1, &n2, sizeof(int));
	printf("After : n1 = %d, n2 = %d\n", n1, n2);

	char c1 = 'A', c2 = 'B';

	printf("Before : c1 = %c, c2 = %c\n", c1, c2);
	//swap_char(&c1, &c2);
	swap(&c1, &c2, sizeof(char));
	printf("After : c1 = %c, c2 = %c\n", c1, c2);


	return 0;
}




















