#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Logger.h"

int intMax = 75;

static int x = 10;
int y = 20;

void fun(int *x){
    log((*x)++);
}

#define LOG(x) printf("%d",x);

int main(int argc, char const *argv[])
{
    static int x= 10;
    static int * y= &x;
    fun(&x);
    fun(y);
    log("x",x);
    log("y",*y);
    return 0;
}