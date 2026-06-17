#include<stdio.h>

float find_average(float marks[], int length);
float find_max(float marks[], int length);
int search_key(float marks[], int length, float key);

int main(void)
{
	float marks[5] = {89.5f, 67.5f, 72.8f, 95.7f, 63.4f};

	printf("Avg marks = %f\n", find_average(marks, 5));
	
	printf("Max marks = %f\n", find_max(marks, 5));

	int ret = search_key(marks, 5, 72.8f);
	if(ret == -1)
		printf("key is not found\n");
	else
		printf("Key is found at index %d\n", ret);

	return 0;
}

float find_average(float marks[], int length)
{
	float sum = 0;
	for(int i = 0 ; i < length ; i++)
		sum = sum + marks[i];
		
	return sum / length;
}

float find_max(float marks[], int length)
{
	float max = marks[0];
	for(int i = 1 ; i < length ; i++)
	{
		if(marks[i] > max)
			max = marks[i];
	}
	return max;
}

int search_key(float marks[], int length, float key)
{
	for(int i = 0 ; i < length ; i++)
	{
		if(key == marks[i])
			return i;
	}
	return -1;
}

















