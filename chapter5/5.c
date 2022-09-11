#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("main: %d\n", (int)getpid());
    int rc = fork();
    if(rc == 0) {
        int wc = wait(NULL);
        printf("child: %d\twait: %d\n", (int)getpid(), wc);
        perror("errno"); // https://blog.csdn.net/zhangzhi2ma/article/details/82391248
    } else if(rc > 0) {
        int wc = wait(NULL);
        printf("parent: %d\twait: %d\n", (int)getpid(), wc);
    }
}