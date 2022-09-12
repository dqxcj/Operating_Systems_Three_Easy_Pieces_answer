#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sched.h>

int main() {
    int fd[2];
    pipe(fd);
    int rc1 = fork();
    struct timeval tv1, tv2;
    if(rc1 == 0) {
        cpu_set_t mask;
        CPU_ZERO(&mask);
        CPU_SET(2, &mask);
        sched_setaffinity(0, sizeof(mask), &mask);
        close(fd[1]);
        char buf[200000];
        for (int i = 0; i < 1000; i++) {
            //read(fd[0], buf, sizeof(buf));
            //printf("read%d\n", i);
            ;
        }
        int file = open("./contextSwitchTime_outfile.txt", O_RDWR | O_CREAT | O_APPEND);
        write(file, buf, sizeof(buf));
        //close(fd[0]);
    } else if(rc1 > 0) {
        int rc2 = fork();
        if(rc2 == 0) {
            cpu_set_t mask;
            CPU_ZERO(&mask);
            CPU_SET(2, &mask);
            sched_setaffinity(0, sizeof(mask), &mask);
            close(fd[0]);
            char *info = "hello world!\n";
            gettimeofday(&tv1, NULL);
            for (int i = 0; i < 100000; i++) {
                write(fd[1], info, strlen(info));
                printf("write%d\n", i);
            }
            gettimeofday(&tv2, NULL);
            //close(fd[1]);
        } else if(rc2 > 0) {
            waitpid(rc1, NULL, 0);
            waitpid(rc2, NULL, 0);
            printf("tv2.sec: %ld\ttv2.usec: %ld\ntv1.sec: %ld\ttv1.usec: %ld\n", tv2.tv_sec, tv2.tv_usec, tv1.tv_sec, tv1.tv_usec);
            long int time = (tv1.tv_usec - tv2.tv_usec);
            printf("执行10次用时%ldus, 执行一次用时%ldus\n", time, time / 10);
        }
    }
    return 0;
}