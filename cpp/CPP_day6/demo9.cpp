#include <iostream>
using namespace std;
//Smart pointer

class a
{
    int aa;
    public: 
    a()
    {
        aa=55;
    }
    void print()
    {
        cout<<"\n aa="<<aa;
    }
    void fun1()
    {
        cout << "\n fun1";
    }
    void fun2()
    {
        cout << "\n fun2";
    }
};
class SmartPtr
{
    a *ptr;
    public:
    SmartPtr(a *p = NULL) 
    { 
        ptr = p; 
    }
    ~SmartPtr() 
    { 
        delete (ptr); 
        ptr = NULL;
    }
    a* operator->()
    {
        return ptr;
    }
};

int main()
{
    // a *ptr = new a();
    // ptr->fun1();
    // ptr->fun2();
    // ptr->print();

    SmartPtr obj(new a());
    obj->print();
    obj->fun1();
    obj->fun2();

    
    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is automatically
    // called and destructor does delete ptr.


   

    return 0;
}