#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));
#define LOGsp(s,x) printf("%s : %p\n",(s),(x));

int main(int argc, char const *argv[])
{
    // char s[] = "abcd";
    // s[0] = 'A';
    // LOGs(s[-2]);
    // char *a = "xyz";
    // a[0] = 'g';
    // LOGs(a);
    // unsigned long long p = 1;
    // printf("%d\n" ,sizeof(*s + p));
    // printf("%d\n" ,sizeof(s));
    // printf("%d\n" ,sizeof(a));
    // printf("%c\n" ,a[-1]);
    // printf("%c\n" ,s[-1]);
    // printf("%s\n" ,s[-6]);
    
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p)[4] = a;
    LOGsx("*p",**p);
    return 0;
}