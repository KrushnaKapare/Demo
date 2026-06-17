#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main(void)
{
	int arr[2];

	//1. create a pipe - arr[0] - read end, arr[1] - write end
	int ret = pipe(arr);
	if(ret == -1)
	{
		perror("pipe() is failed");
		_exit(-1);
	}

	//2. write into pipe from write end
	char msg1[64] = "Good Morning !!!";
	write(arr[1], msg1, strlen(msg1));
	printf("msg is written into pipe \n");

	//3. read from pipe form read end
	char msg2[64];
	read(arr[0], msg2, sizeof(msg2));
	printf("msg read from pipe : %s\n", msg2);
	
	//4. close both the ends of pipe
	close(arr[0]);
	close(arr[1]);

	return 0;
}













