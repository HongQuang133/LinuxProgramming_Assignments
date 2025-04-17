//create a child process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    
    pid = fork();
    if(pid >= 0){
        if(0 == pid){
            printf("I am the child process with PID: %d\n", getpid());
            if('1' == *argv[1]){
                execlp("ls", "-l", NULL);
                printf("execlp failed\n");
            } else if('2' == *argv[1]){
                execlp("date","date", NULL);
                printf("execlp failed\n");
            }
        }
        else{
            printf("I am the parent process with PID: %d\n", getpid());
        }
    }
    return 0;
}