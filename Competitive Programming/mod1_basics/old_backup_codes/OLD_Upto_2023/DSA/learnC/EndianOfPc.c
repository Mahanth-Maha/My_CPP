#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(x) printf("%d",x);

int main(int argc, char const *argv[])
{
    // int arr[] = {1,2,3,4};
    // int *p = arr;
    // if(*((char*)p) == *p){
    //     printf("Little Endian\n");
    // } else {
    //     printf("Big Endian\n");
    // }
    // for(int i = 0; i < 4;i++){
    //     printf("Value : %d \t",p[i]);
    //     for(int j = 0;j < sizeof(int) ;j++){
    //         printf("%u\t",*(((char*)(p + i)) + j));
    //     }
    //     printf("\n");
    // }
    double arr[] = {2.0,4.0,-2.0,-4.0};
    double *p = arr;
    if(*((char*)p) == *p){
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
    for(int i = 0; i < 4;i++){
        printf("Value : %d \t",p[i]);
        for(int j = 0;j < sizeof(double) ;j++){
            printf("%u\t",*(((char*)(p + i)) + j));
        }
        printf("\n");
    }
    return 0;
}