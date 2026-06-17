#include<stdio.h>
#define SIZE 9

int comparisons;

int linear_search(int arr[SIZE],int key); 
int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    
    // 1. Get the key from the user.
    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);

    int index = linear_search(arr,key); // function call
    if(index == -1)
        printf("Key Not Found !\n");
    else
        printf("Key found at index %d\n",index);
        
        printf("Comparisons = %d\n",comparisons);

    return 0;
}

int linear_search(int arr[SIZE],int key) // (int *arr, int key)
{
 //2. Start the traversal from the 1st element of the array(0th Index).
    for(int index = 0; index < SIZE; index++)
    {
        // 3. Compare the key to search with each element of the array.
        comparisons++; // 4
        if(key == arr[index])
        {
            // If the match is found, return the corresponding index.
            return index;
        }
        // Else, continue the search till the last index of the array.
    }
    return -1; // key not found : return false
}