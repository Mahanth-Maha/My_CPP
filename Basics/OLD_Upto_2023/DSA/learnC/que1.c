#include <stdio.h>

int main(int argc, char const *argv[])
{
    int k,i=50,j=100,l;
    i = i|(j&&100);
    k = i||(j||100);
    l = i&(j&&100);
    printf("%d %d %d %d",i,j,k,l);

    return 0;
}