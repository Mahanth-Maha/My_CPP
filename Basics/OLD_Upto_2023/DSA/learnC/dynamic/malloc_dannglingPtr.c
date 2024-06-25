#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d",x);

int *assignval (int *x, int val) {
    *x = val;
    return x;
}

int main(int argc, char const *argv[])
{
    int *x = malloc(sizeof(int));
    if (NULL == x) return 0;
    x = assignval (x,0);
    if (x) {
        // x = (int *)malloc(sizeof(int));
        // printf("Memory Leak arised\n");
        // if (NULL == x) return;
        x = assignval (x,10);
    }
    printf("%d\n", *x);
    free(x);
    return 0;
}