#include <stdio.h>


int func(int a){
    return a*a*a;
}

int main(){
    // printf("%d",func(20));
    int c = 0;
    int a = 10;
    int b = 20;
    printf("a: %d b: %d\n",a,b);
    a = (a++ > 10) ? printf("True, %d",a) :  printf("False, %d",a); 
    b = (b-- && b )< 16 ? 2 : 3; 
    printf("a: %d b: %d\n",a,b);
    int t = a;
    a = b;
    b = t;
HERE:
    printf("a: %d b: %d\n",a,b);
    b =(t = a, a = b, t);
    printf("a: %d b: %d\n",a,b);
    b = (a = b-a,10<t+a*func(b+4));
    printf("a: %d b: %d\n",a,b);
    switch (c)
    {   
    case 1:
        printf("1\n");
    default:
        c++;
        c++;
        printf("def: c = %d\n",c);
    case 2:
        c++;
        c++;
        printf("2\n");
    case 3:
        printf("3\n");
    case 4:
        c++;
        c++;
        printf("4\n");
    case 5:
        printf("5\n");
        goto HERE;
    case 6:
        printf("6\n\n");
    }
    int i = 0 ;
Loop:
    i++;
    printf("%d\n",i);
    if(i<10) goto Loop;
    
    return 0;
}