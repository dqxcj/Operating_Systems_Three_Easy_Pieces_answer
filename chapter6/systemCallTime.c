#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

int main() {
    int file = open("./systemCallTime_outfile.txt", O_RDWR | O_CREAT | O_APPEND);
    struct timeval tv1, tv2; // https://blog.csdn.net/Ctrl_qun/article/details/54668999
    gettimeofday(&tv1, NULL);
    for(int i = 0; i < 10000; i++)
        write(file, "nihao\n", 6);
    gettimeofday(&tv2, NULL);
    printf("tv2.sec: %ld\ttv2.usec: %ld\ntv1.sec: %ld\ttv1.usec: %ld\n", tv2.tv_sec, tv2.tv_usec, tv1.tv_sec, tv1.tv_usec);
    long int time = (tv1.tv_usec - tv2.tv_usec);
    printf("执行万次用时%ldus, 执行一次用时%ldus\n", time, time / 10000);
    return 0;
}