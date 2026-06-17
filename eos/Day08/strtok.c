#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[256] = "ls -l -i -a -h";
	char *ptr = NULL;

	ptr = strtok(str, " ");
	
	do{
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}while(ptr != NULL);
	return 0;
}








