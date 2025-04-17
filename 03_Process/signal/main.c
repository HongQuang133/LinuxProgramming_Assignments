#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "signal.h"

void handler_function(){
    printf("Child received SIGUSR1 signal\n");
}
int main(int argc, char *argv[]){
    pid_t pid;

    // Create a child process
    pid = fork();
    if(pid >=0){
        if(0 == pid){
            signal(SIGUSR1, handler_function);
            printf("I am the child process with PID: %d\n", getpid());
            pause();
            exit(0);
        }
        else{
            printf("I am the parent process with PID\n");
            sleep(2);
            kill(pid, SIGUSR1);
        }
    }
}