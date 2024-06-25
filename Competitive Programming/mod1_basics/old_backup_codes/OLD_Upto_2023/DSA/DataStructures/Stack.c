#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));


#define N 5
static int S[N] , top = -1;

void push(int d) {if(top != N-1) S[++top] = d ;}
int pop(){ return (top != -1) ?S[top--]:-1; }
int peek(){ return (top != -1) ?S[top]:-1; }

int main(int argc, char const *argv[])
{
    push(10);
    push(20);
    push(30);
    LOGsx("pop",pop());
    push(40);
    push(50);
    LOGsx("pop",pop());
    push(60);
    LOGsx("peek",peek());
    LOGsx("pop",pop());
    LOGsx("pop",pop());
    LOGsx("pop",pop());
    LOGsx("pop",pop());
    LOGsx("pop",pop());
    LOGsx("pop",pop());

    return 0;
}