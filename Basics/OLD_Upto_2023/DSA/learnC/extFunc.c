#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d",x);

// void f2(void);

// void f2(void){
//     printf("from f2 :");
//     func();
// }
void func(void);
int main(int argc, char const *argv[])
{
    // f2();
    void func(void);
    func();
    return 0;
}

void func(void){
    printf("hi\n");
}

