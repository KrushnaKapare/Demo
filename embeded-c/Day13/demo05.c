#include<stdio.h>

int main(int argc, char *argv[])
{
	printf("Name of program = %s\n", argv[0]);
	
	printf("Count of command line arguments : %d\n", argc);
	
	printf("List of cmd line args : \n");
	//for(int i = 0 ; i < argc ; i++)
	for(int i = 0 ; argv[i] != NULL ; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	
	return 0;
}




















