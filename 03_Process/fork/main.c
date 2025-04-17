#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    // Create a child process
    pid = fork();

    if(pid>=0){
        if(pid==0){
            // Child process
            printf("Child process: PID = %d\n", getpid());
        } else {
            // Parent process
            printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        }
    }

    return 0;
}

