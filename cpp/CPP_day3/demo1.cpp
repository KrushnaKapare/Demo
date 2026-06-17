#include<stdio.h>
//namespace demo


int g = 100;
namespace ns1
{
    int connector = 2009;
    namespace nns
    {
        int var = 200;
    }
}
namespace ns2
{
    int connector = 3307;
    int num1 = 11;
    int num2 = 12;
    int num3 = 13;
    int num4 = 14;
    int num5 = 15;
    int num6 = 16;
}


int main()
{
    printf("\n g = %d ", g);
    printf("\n ::g = %d ",::g);
    printf("\n ::connector = %d ",ns1::connector);
    printf("\n ns1::nns::var=%d",ns1::nns::var);
    printf("\n num2 = %d",ns2::num2);
    //printf("\n num2 = %d",num2);//error
    using namespace ns2;
    printf("\n num2 = %d",num2);
    printf("\n num2 = %d",ns2::num2);

    return 0;
}