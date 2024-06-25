#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d",x);

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char *a = "hello";
    printf("s:%s - Size : %u\n",s,sizeof(s));
    printf("a:%s - Size : %u\n",a,sizeof(a));
    printf("s:%p\n",s);
    printf("&s:%p\n",&s);
    printf("a:%p\n",a);
    printf("&a:%p\n",&a);
    // for(int i= 0;i< 6;i++){
    //     printf("s[0]:%c\t %p\n",s[i],&s[i]);
    //     printf("a[0]:%c\t %p\n",a[i],&a[i]);
    // }
    printf("%s",s);
    s[0] = 'H';
    printf("\n%s\n s is modifiable\n",s);
    printf("%s",a);
    a[0] = 'H';
    printf("\n%s\n a is modifiable\n",a);
    return 0;
}