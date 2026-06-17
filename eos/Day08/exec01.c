#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

// create child process and load child.out into newly created process

int main(void)
{
    int ret, s, pid;
    printf("program started \n");
    pid = fork();
    if(pid == 0){
        // child
        ret = execl("./child.out", "child.out", "one", "two", "three", "four", NULL);
        if(ret == -1){
            printf("execl() is failed\n");
            _exit(ret);
        }
    }
    else{
        // parent
        waitpid(pid, &s, 0);
        printf("Exist status of child = %d\n", WEXITSTATUS(s));
    }
    printf("program finished\n");
    return 0;
}
