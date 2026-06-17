#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned long size = 1 * 1024 * 1024 * 1024;
	char *ptr = (char*)malloc(size);
	printf("malloc() returned: %p\n", ptr);
	//getchar();
	for(int i=0; i<size; i+=4096)
		ptr[i] = 'A';
	printf("written on memory allocated by malloc().\n");
	getchar();
	free(ptr);
	ptr = NULL;
	return 0;
}

