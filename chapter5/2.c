#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int file = open("./2_outfile.txt", O_CREAT | O_RDWR);
    printf("file = %d (main pid: %d)\n", file, (int)getpid());
    write(file, "main\n", 5);
    int rc = fork();
    if(rc == 0) {
        printf("file = %d (pid: %d)\n", file, (int)getpid());
        write(file, "child\n", 6);
    } else if(rc > 0) {
        printf("file = %d (pid: %d)\n", file, (int)getpid());
        write(file, "parent\n", 7);
    }
    return 0;
}