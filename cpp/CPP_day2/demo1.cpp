#include<stdio.h>
int main()
{
    bool b = true; //false
    printf("\n value of bool b =%d and size of b = %d",b,sizeof(b));

    wchar_t wch = 'A';
    printf("\n value of wchar_t wch = %c and size of wch = %d",wch,sizeof(wch));
    return 0;
}