#include <stdio.h>
#include <stdlib.h>

int main()
{
    // size_t i, size = 10000;
    size_t i, size = 1 * 1000 * 1000 * 1000;
    char *ptr;
    for (i = 1; i <= 1000; i++)
    {
        ptr = malloc(size);
        printf("%d. malloc() returned: %p\n", i, ptr);
        getchar();
    }
    return 0;
}
