#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "Logger.h"
int x = 10;
// extern y;
// y = 20;
int y = 4;
int y;

// extern float e = 5.6f;
float e = 6.56f;
float e;


#define LOG(x) printf("%f\n",x);
#define LOGx(x) printf("%d\n",x);

void fun(){
    // int y;
    extern int y;
    y = 231;
    // LOGx(y);
    LOGx(y);
}

int main(int argc, char const *argv[])
{
    // float e = 2.4f;
    extern float e;
    extern float e;
    LOG(e);
    LOGx(x);
    LOGx(y);
    fun();
    return 0;
}