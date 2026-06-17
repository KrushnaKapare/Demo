#include<stdio.h>

// gcc main.c -o main.out
//	./main.out one two three four

int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);

	printf("Command line arguments : \n");
	for(int i = 0 ; argv[i] != NULL ; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	
	return 0;
}
