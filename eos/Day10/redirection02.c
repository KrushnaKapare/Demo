#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(void)
{
	int pid = fork();
	if(pid == 0)
	{
		int ifd, ofd, efd;

		// input redirection
		ifd = open("in.txt", O_RDONLY);
		dup2(ifd, 0);
		close(ifd);

		// output redirection
		ofd = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(ofd, 1);
		close(ofd);

		// error redirection
		efd = open("err.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(efd, 2);
		close(efd);

		// child
		int ret = execl("/usr/bin/bc", "bc", NULL);
		if(ret == -1)
		{
			perror("execl() is failed");
			_exit(-1);
		}
	}
	else
	{
		// parent
		int s;
		waitpid(-1, &s, 0);
		printf("Exit status of child : %d\n", WEXITSTATUS(s));
	}

	return 0;
}



