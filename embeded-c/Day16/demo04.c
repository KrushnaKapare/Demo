#include<stdio.h>

#define PI 3.142
#define SQR(n) n * n

int main(void)
{
	int rad;
	float area;

	printf("Enter radius of a circle : ");
	scanf("%d", &rad);
	
	area = PI * SQR(rad);

	printf("Area of a circle = %f\n", area);

	return 0;
}




















