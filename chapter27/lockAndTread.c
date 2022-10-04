#include <stdio.h>
#include <assert.h>
#include <pthread.h>

int i = 0;
pthread_mutex_t lock;
void *myThread(void *arg) {
    for(int j = 0; j < 50000; j++) {
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    pthread_t p1, p2;
    int rc;
    rc = pthread_mutex_init(&lock, NULL); assert(rc == 0); //初始化锁
    printf("main: begin \n");
    rc = pthread_create(&p1, NULL, myThread, NULL); assert(rc == 0);
    rc = pthread_create(&p2, NULL, myThread, NULL); assert(rc == 0);
    rc = pthread_join(p1, NULL); assert(rc == 0);
    rc = pthread_join(p2, NULL); assert(rc == 0);
    printf("i = %d\nmain: end\n", i);
    return 0;
}