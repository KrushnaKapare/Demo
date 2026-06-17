#include<iostream>
using namespace std;
//singleton class

class singleton
{
    static singleton *ptr;
    private:
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

    void PrintMessage()
    {
        cout<<"\n Singleton Design pattern demo ";
    }
};//end of class

//global definition of static data member
singleton* singleton::ptr = NULL;


int main()
{
    singleton *ptr1 = singleton::getObject();
    cout<<"\n address of ptr1"<<ptr1;
    ptr1->PrintMessage();

    singleton *ptr2 = singleton::getObject();
    cout<<"\n address of ptr1"<<ptr2;

    singleton *ptr3 = singleton::getObject();
    cout<<"\n address of ptr1"<<ptr3;

    singleton *ptr4 = singleton::getObject();
    cout<<"\n address of ptr1"<<ptr4;
    
    return 0;
}