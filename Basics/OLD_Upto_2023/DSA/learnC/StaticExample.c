#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d\t",x);

int f(int);
int g(int);

int f(int i){
    static int X = 0;
    X += i;
    X = g(X);
    return X;
}

int g(int i){
    static int Y = 0;
    Y += i;
    return Y;
}

int main(int argc, char const *argv[])
{
    int i,j;
    for(int i= 0;i<= 6;i++){
        j = f(i);
        LOG(j);
    }
    printf("%d",j);
    return 0;
}