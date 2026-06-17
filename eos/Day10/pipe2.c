#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main(void)
{
	int arr[2];
	int ret = pipe(arr);
	if(ret == -1)
	{
		perror("pipe() is failed");
		_exit(-1);
	}

	int pid = fork();
	if(pid == 0)
	{
		// child process - writer
		close(arr[0]);		// close the read end of pipe
		char str[64];
		printf("child : Enter msg : ");
		scanf("%[^\n]s", str);
		write(arr[1], str, strlen(str));
		printf("child : msg is written into pipe !!!\n");
		close(arr[1]);
	}
	else
	{
		// parent process - reader
		close(arr[1]);		// close the write end of pipe
		printf("parent : waiting for msg ....\n");
		char str[64];
		read(arr[0], str, sizeof(str));
		printf("parent : received msg : %s\n", str);
		close(arr[0]);

		int s;
		wait(&s);
	}

	return 0;
}











