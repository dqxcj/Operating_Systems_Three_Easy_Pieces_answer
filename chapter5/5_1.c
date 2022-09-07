#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
    int x;
    x = 100;
	printf("Hello, I'm %d  x: %d (pid:%d)\n", (int) getpid(), x,  (int) getpid());
    int rc = fork();
    if(rc < 0) 
        printf("rc < 0   rc: %d (pid: %d)\n", rc, (int) getpid());
    else if(rc == 0)
    {
		printf("I'm child  x: %d (pid: %d)\n", x, (int)getpid());
		x = 50;
        printf("I'm child  x: %d (pid: %d)\n", x, (int)getpid());
    }
    else 
    {
		int wc = wait(NULL);
		printf("I'm parent of %d  x: %d(pid: %d)\n", rc, x, (int)getpid());
		x = 200;
        printf("I'm parent of %d  x: %d(pid: %d)\n", rc, x, (int)getpid());
    }
    return 0;
}
