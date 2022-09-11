#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("main: %d\n", (int)getpid());
    char *arr[] = {"ls", "-a", NULL};
    if(!fork()) {
        printf("execl\n");
        if(execl("/bin/ls", "ls", "-a", NULL) == -1) {
            printf("execl error\n");
            exit(1);
        }
    }
    wait(NULL);
    if(!fork()) {
        printf("execle\n");
        if(execle("/bin/ls", "ls", "-a", NULL, NULL) == -1) {
            printf("execle error\n");
            exit(1);
        }
    }
    wait(NULL);
    if(!fork()) {
        printf("execlp\n");
        if(execlp("ls", "ls", "-a", NULL) == -1) {
            printf("execlp error\n");
            exit(1);
        }
    }
    wait(NULL);
    if(!fork()) {
        printf("execv\n");
        if(execv("/bin/ls", arr) == -1) {
            printf("execv error\n");
            exit(1);
        }
    }
    wait(NULL);
    if(!fork()) {
        printf("execve\n");
        if(execve("/bin/ls", arr, NULL) == -1) {
            printf("execve error\n");
            exit(1);
        }
    }
    wait(NULL);
    if(!fork()) {
        printf("execvp\n");
        if(execvp("ls", arr) == -1) {
            printf("execvp error\n");
            exit(1);
        }
    }
    return 0;
}