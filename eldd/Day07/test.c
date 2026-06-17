#include <stdio.h>

int main()
{
    printf("sizeof char = %lu\n", sizeof(char));
    printf("sizeof short = %lu\n", sizeof(short));
    printf("sizeof int = %lu\n", sizeof(int));
    printf("sizeof long = %lu\n", sizeof(long));
    printf("sizeof long long = %lu\n", sizeof(long long));
    return 0;
}
// homework -- compile same code in bbb and execute it.
// > vim test.c
// > gcc test.c
// > ./a.out
