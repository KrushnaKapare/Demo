#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp
void selection_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
   // int arr[SIZE] = {30,20,60,50,10,40};
   int arr[SIZE] = {11,22,33,44,55,66}; // sorted array
    printf("\n Before Sort :\n");
    display(arr);
    printf("\n After Sort :\n");
    selection_sort(arr);
    display(arr);
    return 0;
}

void selection_sort(int arr[SIZE])
{
    int sel_pos,pos;
    int it=0,comp=0;
    for(sel_pos = 0; sel_pos < SIZE-1; sel_pos++)
    {
        it++;
        for(pos = sel_pos+1; pos < SIZE; pos++)
        {
            comp++;
            if(arr[sel_pos] > arr[pos])
            {
                // swap
                // #define SWAP(a,b) int temp=a; a=b; b=temp;
                SWAP(arr[sel_pos],arr[pos]);
                /*
                    int temp = arr[sel_pos];
                    arr[sel_pos] = arr[pos];
                    arr[pos] = temp;
                */
            }   
        }
    }   
    printf("\n Iterations = %d  comparisons = %d\n",it,comp);
}

void display(int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}