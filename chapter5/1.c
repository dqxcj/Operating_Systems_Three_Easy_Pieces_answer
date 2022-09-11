#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("parent: %d\n", (int)getpid());
    int x = 100;
    int rc = fork();
    if(rc == 0) {
        x = 80;
        printf("x = %d (pid: %d)\n", x, (int)getpid());
    } else if(rc > 0) {
        int wc = wait(NULL);
        x = 120;
        printf("x = %d (pid: %d)\n", x, (int)getpid());
    }
    return 0;
}