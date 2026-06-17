#include<stdlib.h>
#include<iostream>
using namespace std;
// new and delete => basic concept

int main()
{
    //1 int using malloc()
    int *ptr1 = (int*)malloc(4);
    *ptr1 = 10;
    cout<<"\n value at *ptr1="<<*ptr1;
    free(ptr1);
    ptr1 = NULL;

    //1 int using new
    int *ptr2 = new int;
    *ptr2 = 11;
    cout<<"\n value at *ptr2="<<*ptr2;
    delete ptr2;
    ptr2 = NULL;



    //5 int using malloc()
    int *ptr3 = (int*)malloc(5*4);
    for (int i = 0; i < 5; i++)
    {
        ptr3[i]=i+5;
        cout<<"\n value at ptr3["<<i<<"] = "<<ptr3[i];
    }
    free(ptr3);
    ptr3 = NULL;

    //5 int array using new
    int *ptr4=new int[5];
    for (int i = 0; i < 5; i++)
    {
        ptr4[i]=i+90;
        cout<<"\n value at ptr4["<<i<<"] = "<<ptr4[i];
    }
    delete []ptr4;
    ptr4 = NULL;
   

    cout<<"\n";
    return 0;
}



