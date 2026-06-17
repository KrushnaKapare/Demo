#include<stdio.h>
#include<stdlib.h>

// ./my_cp.out <src file path> <dest file path>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Run program as : ./my_cp.out <src file path> <dest file path>\n");
		exit(1);
	}
	// program file : argv[0]
	// src file		: argv[1]
	// dest file	: argv[2]

	//1. open src file in read mode and dest file in write mode
	FILE *s_fp = fopen(argv[1], "r");
	FILE *d_fp = fopen(argv[2], "w");

	//2. read from src file and write into dest file
	char ch;
	while((ch = fgetc(s_fp)) != EOF)
		fputc(ch, d_fp);

	//3. close both the files
	fclose(s_fp);
	fclose(d_fp);

	return 0;
}




















