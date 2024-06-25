#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d",x);


void fun1(char a[]){
    printf("%s",a);
}

int main(int argc, char const *argv[])
{
    char *s = "Maha";
    const char *s1 = "mahaa";
    char a[] = "Maha";
    fun1(s);
    fun1(s1);
    fun1(a);

    return 0;
}