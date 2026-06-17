#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp

void bubble_sort(int arr[SIZE]);
void efficient_bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
   // int arr[SIZE] = {30,20,60,50,10,40};
   int arr[SIZE] = {11,22,33,44,55,66};
    printf("\n Before Normal Bubble Sort :\n");
    display(arr);
    printf("\n After Normal Bubble Sort :\n");
    bubble_sort(arr);
    display(arr);

    printf("\n Before Efficient Bubble Sort :\n");
    display(arr);
    printf("\n After Efficient Bubble Sort :\n");
    efficient_bubble_sort(arr);
    display(arr);


    return 0;
}

// normal bubble sort
void bubble_sort(int arr[SIZE])
{
    int Iterations=0,comp=0;
    for(int it = 0; it < SIZE-1; it++) // its : n-1 : 0 to  < 6-1
    {
        Iterations++;
        for(int pos= 0; pos < SIZE-1-it; pos++)
        {
            comp++;
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);
            }
        }
    }
    printf("\n Iterations = %d,comparisons = %d\n",Iterations,comp);
}

void efficient_bubble_sort(int arr[SIZE])
{
    int flag,Iterations = 0, comp=0;
    for(int it = 0; it < SIZE-1; it++) // its : n-1 : 0 to  < 6-1
    {
        flag = 0;
        Iterations++;
        for(int pos= 0; pos < SIZE-1-it; pos++)
        {
            comp++;
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    printf("\n Iterations = %d,comparisons = %d\n",Iterations,comp);
}

void display(int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}