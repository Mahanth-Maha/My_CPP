#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d",x);

int main(int argc, char const *argv[])
{
    int *p,i = 0;
    do{
        p = malloc(1024*1024*1024*sizeof(int));
        printf("i = %9d\talloc at %p\n",i++,p);
    }while(p != NULL);
    return 0;
}

/*
Crashed at 
for(2^30) alloc per time
i =        10   alloc at 000001fa71ea0040
i =        11   alloc at 000001fb71eba040
i =        12   alloc at 000001fc71ec4040
i =        13   alloc at 0000000000000000
*/