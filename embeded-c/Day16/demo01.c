#include<stdio.h>

#define PI 3.142

int main(void)
{
	int rad;
	float area;

	printf("Enter radius of a circle : ");
	scanf("%d", &rad);
	
	area = PI * rad * rad;

	printf("Area of a circle = %f\n", area);

	return 0;
}




















