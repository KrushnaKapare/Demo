#include<stdio.h>
#define SIZE 6

void insertion_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
    int arr[SIZE] = {55,44,22,66,11,33};
    printf("\n Before Sort :\n");
    display(arr);
    printf("\n After Sort :\n");
    insertion_sort(arr);
    display(arr);
    return 0;
}

void insertion_sort(int arr[SIZE])
{
    int i,j,temp;
    for(i=1; i < SIZE; i++)
    {
        temp = arr[i]; 
        for(j = i-1; j>=0 && temp < arr[j]; j--)
        {
            // shift arr[j] to j+1 index
            arr[j+1] = arr[j];
            // decrement j
        }
        // copy temp to j+1 index
        arr[j+1] = temp;
    }
}

void display(int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}