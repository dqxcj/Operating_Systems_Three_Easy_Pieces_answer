#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    int rc1 = fork();
    if(rc1 == 0) {
        close(fd[0]);
        char *info = "hello world!\n";
        write(fd[1], info, strlen(info));
        printf("strlen(info): %d\tsizeof(info): %d\n", (int)strlen(info), (int)sizeof(info)); // https://blog.csdn.net/zhaocx111222333/article/details/109142273
        close(fd[1]);
    } else if(rc1 > 0) {
        int rc2 = fork();
        if(rc2 == 0) {
            close(fd[1]);
            char buf[1024];
            read(fd[0], buf, sizeof(buf)); // https://blog.csdn.net/hhhlizhao/article/details/71552588
            printf("sizeof(buf): %d\n", (int)sizeof(buf));
            close(fd[0]);
            printf("%s", buf);
        }
    }
    return 0;
}