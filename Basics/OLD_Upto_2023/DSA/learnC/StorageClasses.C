#include <stdio.h>
#include "Logger.h"

int p = 20;
int x = 20;
static int y = 2;
void fun(){
    static int y = 5;
    int x = 50;
    log("in Func 1\ty",y);
    log("in Func 1\tx",x);
}

void fun2(){
    log("in Func 2\ty",y);
    log("in Func 2\tx",x);
}

int main(){
    static int y = 1;
    int x = 10;
    log("in Main \ty",y);
    log("in Main \tx",x);
    fun();
    fun2();
    // float i = 2.346f;
    // auto k = i;
    // int j = i;
    // // log("auto");
    // // printf("%f",k);
    // log(k);
    // log(j);
    // for(; i < 5;i++){
    //     auto p = k*6;
    //     log(p);
    // }
    // log(p);
    return 0;
}