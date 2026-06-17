#include<stdio.h>


void make_heap(int arr[]);
int delete_max(int arr[]);
int display(int arr[]);
void heap_sort(int arr[]);

int size = 10;

int main()
{ 
    int arr[11] = {0,20,12,35,15,10,80,30,17,2,1};
    display(arr);
    make_heap(arr);
   // heap_sort(arr);
    display(arr);
    return 0;
}

void make_heap(int arr[]) // max heap
{
    for(int i = size/2; i>=1; i--)
    {
        int ci = i * 2;
        
        while(ci <= size)
        {
            // find parent
            int pi = ci / 2;
        // check if right child is available
        // if yes, check if it is greater than its sibling
        if((ci+1) <= size && arr[ci+1] > arr[ci])
            ci = ci + 1;

      //  if parent is greater than its greatest child then break
        if(arr[pi] > arr[ci])
            break;

        // if max child is greater than parent
        // swap the parent and max child
        int temp = arr[ci];
        arr[ci] = arr[pi];
        arr[pi] = temp;
        
        // repeat the process for further child
        ci = ci * 2;
        }
       
    }
}

int delete_max(int arr[])
{
    // swap 1st and last element
    int max = arr[1];
    arr[1] = arr[size];
    arr[size] = max;
    size--;

   
    int ci = 1 * 2;

    while(ci <= size)
    {
        //5. find index of parent
        int pi = ci / 2;
        //6. find maximum child of pi index element
        if((ci + 1) <= size && arr[ci + 1] > arr[ci])
            ci = ci + 1;
        //7. if parent is greater than maximum child, then stop
        if(arr[pi] > arr[ci])
            break;
        //8. if maximum child is greater than parent, then swap parent and maximum child
        int temp = arr[ci];
        arr[ci] = arr[pi];
        arr[pi] = temp;
        //9. update child index
        ci = ci * 2;
    }
    return max;
}

int display(int arr[])
{
    for(int i = 1; i< 11 ; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void heap_sort(int arr[])
{
    make_heap(arr);

  
    for(int i =1;i< 11;i++)
    {
        delete_max(arr);
    }

   
    printf("\n");
}