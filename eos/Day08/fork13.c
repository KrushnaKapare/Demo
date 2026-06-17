#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int ret, count = 0;
    printf("program started\n");
    while(1){
        ret = fork();
        if(ret == -1){  // failure
            printf("fork() is failed\n");
            _exit(0);
            //break;
        }
        else if(ret == 0){  // child
            for(int i = 1 ; i <= 5 ; i++){
                sleep(1);
            }
            _exit(0);
        }
        else{   // parent
            count++;
            printf("Process count = %d\n", count);
        }
    }
    // think of clearing the PCB's of child process
    // exploer the return value of wait/waitpid --> PID of process whose exit status is read
    //while(waitpid(-1, &s, 0) != -1){
        // print exit status of child processes
    //}
    printf("program finished\n");
    return 0;
}