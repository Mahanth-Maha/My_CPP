#include <stdio.h>

int sqr(int );

main(int argc, char const *argv[])
{
    printf("%d",2);
    sqr(3);
}

int sqr(int a){
    printf("%d",a);
    return (float)a*a;
}