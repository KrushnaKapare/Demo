#include <stdio.h>

int num1 = 10;
int num2;

int main()
{
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    return 0;
}

// > gcc memory1.c -m32
// > file a.out
// > readelf -a a.out
// > objdump -h a.out

