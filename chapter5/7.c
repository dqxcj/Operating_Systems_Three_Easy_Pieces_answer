#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    printf("main (pid: %d)\n", (int)getpid());
    if(!fork()) {
        close(STDOUT_FILENO);
        open("./7_outfile.txt", O_CREAT | O_RDWR);
        printf("child hello world! (pid: %d)\n", (int)getpid());
    }
    printf("main hello world! (pid: %d)\n", (int)getpid());
    return 0;
}