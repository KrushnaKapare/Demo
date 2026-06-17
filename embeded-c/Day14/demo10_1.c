#include<stdio.h>

int main(void)
{
	int num = 10;
	char ch = 'A';
	double d = 3.142;
	
	//1. open file in write mode
	FILE *fp = fopen("file3.txt", "w");

	fprintf(fp, "%d %c %lf\n", num, ch, d);

	//3. close the file
	fclose(fp);

	printf("Data is written into file !!!\n");

	return 0;
}




















