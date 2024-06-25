#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));

#define N 31

int main(int argc, char const *argv[])
{
    int *arr = malloc(sizeof(int)*N);
    for(int i = 0 ;i < N;i++)arr[i] = i;
    for(int i = 0 ;i < N;i++){
        printf("indexed : %3d -> Parent = %3d ; Child{ Left = %3d , Right = %3d}\n",i,(i-1)/2,2*i+1,2*i+2);
    }

    return 0;
}