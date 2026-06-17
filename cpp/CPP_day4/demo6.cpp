#include<iostream>
using namespace std;
//overload [] oparator
class array
{
    int *ptr;
    int size;
    public:
    array(int s)
    {
        this->size=s;
        this->ptr=new int[size];
        for (int i = 0; i < this->size; i++)
        {
            this->ptr[i]=i+2;
        }  
    }
    array(const array& a1)
    {
        this->size=a1.size;
        this->ptr=new int[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->ptr[i]=a1.ptr[i];
        }  
    }
    void printArray()
    {
        for (int i = 0; i < 5; i++)
        {
            cout<<"\n ptr["<<i<<"]="<<this->ptr[i];
        }
    }
    ~array()
    {
        cout<<"\n --- ~array()---";
        if(this->ptr!=NULL)
            delete[]this->ptr;
        this->ptr=NULL;
    }
    int& operator[](int index)
    {
        if( index >= this->size )
        {
            cout<<"\n invalid index ";
            exit(0);
        }
        return this->ptr[index];
    }

};

int main()
{ 
   
    // int arr[5] = {22,44,55,66,88};
    // int sec_ele = arr[1];
    // cout<<"\n sec element = "<<sec_ele;

    // array a1(5);
    // a1.printArray();
    // sec_ele = a1[1];
    // cout<<"\n sec element = "<<sec_ele;


    //update value at 3rd index 66 => 100
    int arr1[5] = {22,44,55,66,88};
    arr1[3] = 100;
    for (int i = 0; i < 5; i++)
    {
        cout<<"\n arr1["<<i<<"]="<<arr1[i];
    }
    

    array a1(5);
    a1.printArray();
    //update value at 3rd index 5 => 100
    a1[3] = 100;
    a1.printArray();



    return 0;
}