#include<stdio.h>

int main(void)
{
	int num;
	char ch;
	double d;
	
	//1. open file in read mode
	FILE *fp = fopen("file3.txt", "r");

	fscanf(fp, "%d %c %lf", &num, &ch, &d);
	
	printf("num = %d\nch = %c\nd = %lf\n", num, ch, d);

	//3. close the file
	fclose(fp);


	return 0;
}




















