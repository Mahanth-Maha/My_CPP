#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d",x);

int main(int argc, char const *argv[])
{
    int i =10;
    void * p = &i;
    printf("%d\n",(p));
    p = (int* )&i;
    printf("%d\n",*((int*)p));
    return 0;
}