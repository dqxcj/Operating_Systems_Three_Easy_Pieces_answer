#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    printf("main: %d\n", (int)getpid());
    int rc = fork();
    if(rc == 0) {
        printf("hello (pid: %d)\n", (int)getpid());
    } else if(rc > 0) {
        printf("goodbye (pid: %d)\n", (int)getpid());
    }
    return 0;
}