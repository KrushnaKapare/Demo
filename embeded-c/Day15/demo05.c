#include<stdio.h>
#include<stdlib.h>

// void qsort(void *base, size_t nmemb, size_t size,
//                  int (*compar)(const void *, const void *));
//		base - base address of array
//		nmenb - no of elements in array
//		size - size of individual element of array (bytes)
//		compar - address of comparision function

int compare1(const void *ptr1, const void *ptr2)
{
	return *(int *)ptr1 - *(int *)ptr2;
}

int compare2(const void *ptr1, const void *ptr2)
{
	return *(char *)ptr1 - *(char *)ptr2;
}

int main(void)
{
	int arr1[6] = {33, 66, 55, 22, 44, 11};
	char arr2[6] = {'P', 'G', 'D', 'E', 'S', 'D'};

	printf("Array before sort : ");
	for(int i = 0 ; i < 6 ; i++)
		//printf("%-4d", arr1[i]);
		printf("%-4c", arr2[i]);
	printf("\n");

	//qsort(arr1, 6, sizeof(int), compare1);
	qsort(arr2, 6, sizeof(char), compare2);

	printf("Array after sort : ");
	for(int i = 0 ; i < 6 ; i++)
		//printf("%-4d", arr1[i]);
		printf("%-4c", arr2[i]);
	printf("\n");
	return 0;
}




















