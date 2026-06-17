
// int chdir(const char *path)
//		arg1 - path of a new working directory
//		returns - 0 on success
//				- -1 on error

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char *dirpath;
	char cwd[256];

	if(argc != 2)
	{
		printf("Directory path is not mentioned ...\n");
		printf("Run as : %s <dir path>\n", argv[0]);
		exit(1);
	}

	dirpath = argv[1];

	printf("Before : %s\n", getcwd(cwd, sizeof(cwd)));
	
	int ret = chdir(dirpath);
	if(ret == -1)
	{
		printf("chdir() is failed to change directory\n");
		exit(ret);
	}

	printf("After : %s\n", getcwd(cwd, sizeof(cwd)));
	
	return 0;
}









