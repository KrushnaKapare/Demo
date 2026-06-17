#include<iostream>
using namespace std;
//singleton class

class singleton
{
    private:
    static singleton *ptr;
    singleton()
    {
        cout<<"\n ----------singleton()--------";
    }
    public:
    static singleton* getObject()
    {
        if( ptr == NULL)
                ptr=new singleton();
        return ptr;
    }
    static void releaseObject()
    {
        if(ptr != NULL)
            delete ptr;
        ptr = NULL;    
    }
   void PrintMessage()
    {
        cout<<"\n Singleton Design pattern demo ";
    }
    ~singleton()
    {
        cout<<"\n -------- ~singleton()---------";
    }
};//end of class

//global definition of static data member
singleton* singleton::ptr = NULL;

int main()
{
    singleton *ptr1 = singleton::getObject();
    cout<<"\n address of ptr1 = "<<ptr1;
    ptr1->PrintMessage();

    singleton *ptr2 = singleton::getObject();
    cout<<"\n address of ptr2 = "<<ptr2;

    singleton::releaseObject();

    singleton *ptr3 = singleton::getObject();
    cout<<"\n address of ptr3 = "<<ptr3;

    singleton *ptr4 = singleton::getObject();
    cout<<"\n address of ptr4 = "<<ptr4;
    
    singleton::releaseObject();
    
    //delete ptr1;
    return 0;
}