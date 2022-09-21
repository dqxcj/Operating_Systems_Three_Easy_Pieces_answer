#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 9;
    printf("%d\n", *ptr);
    return 0;
}