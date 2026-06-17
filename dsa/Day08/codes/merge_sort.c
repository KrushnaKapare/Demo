#include<stdio.h>
#include<stdlib.h>
#define SIZE 9

void merge_sort(int arr[SIZE],int left,int right);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    printf("\n Before Sort :\n");
    display(arr);
    merge_sort(arr,0,SIZE-1);
    printf("\n After Sort :\n");
    display(arr);
    return 0;
}

void merge_sort(int arr[SIZE],int left,int right)
{
    int mid = (left + right) / 2;

    if(left >= right)
        return;

    merge_sort(arr,left,mid); // left sub array
    merge_sort(arr,mid+1,right); // right sub array

    // merge the sub array in a sorted order in a temp array
    int temp_size = right-left + 1;

    int *ptr = malloc(sizeof(int)*temp_size);

    int i = left, j = mid+1, k = 0;

    while(i<= mid && j <= right)
    {
        // ptr[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
        if(arr[i] < arr[j])
        {
            ptr[k] = arr[i];
            i++; k++;
        }
        else
        {
            ptr[k] = arr[j];
            j++; k++;
        }
    }
    while(i <= mid)
    {
        ptr[k++] = arr[i++];
    }
    
    while(j <= right)
    {
        ptr[k++] = arr[j++];
    }
    // copy the sorted data of temp array into the main array
    for(int i = 0; i < temp_size;i++)
    {
        arr[left + i] = ptr[i]; // 5
    }
    free(ptr);
    ptr = NULL;
}

void display(int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}