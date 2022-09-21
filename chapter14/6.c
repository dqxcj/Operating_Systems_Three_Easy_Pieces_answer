#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(100 * sizeof(int));
    data[10] = 999;
    free(data);
    printf("data[10]: %d\n", data[10]);
    return 0;
}