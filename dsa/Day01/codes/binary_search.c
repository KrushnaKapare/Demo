#include<stdio.h>
#define SIZE 9
int binary_search(int arr[SIZE],int key);
int rec_binary_search(int arr[SIZE],int key,int left,int right);
int main()
{
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};

    // 1. get the key from the user
    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);
    int index = binary_search(arr,key);
    if(index == -1)
        printf("Key not Found !\n");
    else
        printf("Key found at index %d\n",index);

    printf("\n Recursive Function call :\n ");
        // recursive binary search
    int res = rec_binary_search(arr,key,0,SIZE-1);
    if(res == -1)
        printf("Key not Found !\n");
    else
        printf("Key found at index %d\n",res);

    return 0;
}

int binary_search(int arr[SIZE],int key)
{
    // 2. divide the array
    // find left, right and mid index
    int left = 0,right = SIZE-1, mid;
while(left <= right)
{
    mid = (left+right) / 2;
    // 3. compare the key with mid element
    if(key == arr[mid])
        return mid; // return the index
    // 4. check if the key is smaller or greater
    if(key < arr[mid])
    {
        // continue the search in left sub-array
        right = mid-1;
    }
    else
    {
        // // continue the search in Right sub-array
        left = mid+1;
    }
}
return -1; // key not found
}

int rec_binary_search(int arr[SIZE],int key,int left,int right)
{
    if(left > right)
        return -1;
    int res;
    int mid = (left+right)/2;

    if(key == arr[mid])
        return mid;

    if(key < arr[mid]) // consider left sub-array
    {
        res = rec_binary_search(arr,key,left,mid-1);
    }
    else // consider Right sub-array
    {
        res = rec_binary_search(arr,key,mid+1,right);
    }
    return res;

}