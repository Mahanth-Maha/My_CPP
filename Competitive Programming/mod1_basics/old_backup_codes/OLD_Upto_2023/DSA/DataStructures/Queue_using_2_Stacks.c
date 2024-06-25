#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));

#define N 5
typedef struct St { int *s, top;} Stack;

Stack* initStack(){
    Stack *S = malloc(sizeof(Stack));
    S->s = malloc(sizeof(int)*N); 
    for(int i = 0 ; i < N ; i ++) S->s[i] = 0;
    S->top = -1;
    return S;
}
void push(Stack *S,int d) {if(S->top != N-1) S->s[++S->top] = d ;}
int pop(Stack *S){ return (S->top != -1) ?S->s[S->top--]:-1; }
int peek(Stack *S){ return (S->top != -1) ?S->s[S->top]:-1; }

void printStacks(Stack *S1,Stack *S2){
    printf("S1 : ");
    for(int i = 0 ;i < N; i++) printf("%5d",S1->s[i]);
    printf("\nS2 : ");
    for(int i = 0 ;i < N; i++) printf("%5d",S2->s[i]);
    printf("\n");
}

void enqueue(Stack *S1, Stack *S2,int d) {
    // Version 1
    push(S1,d);
}
int dequeue(Stack *S1, Stack *S2){ 
    // Version 1
    int d;
    if( (d = pop(S2))!= -1) return d;
    while((d = pop(S1)) != -1)
        push(S2,d);
    return pop(S2);
}

int main(int argc, char const *argv[])
{
    Stack *S1 = initStack(),*S2 = initStack();
    enqueue(S1,S2,10);
    enqueue(S1,S2,20);
    enqueue(S1,S2,30);
    LOGsx("dequeue",dequeue(S1,S2));
    enqueue(S1,S2,40);
    enqueue(S1,S2,50);
    LOGsx("dequeue",dequeue(S1,S2));
    enqueue(S1,S2,60);
    printStacks(S1,S2);
    enqueue(S1,S2,70);
    printStacks(S1,S2);
    enqueue(S1,S2,80);
    printStacks(S1,S2);
    enqueue(S1,S2,90);
    LOGsx("dequeue",dequeue(S1,S2));
    LOGsx("dequeue",dequeue(S1,S2));
    LOGsx("dequeue",dequeue(S1,S2));
    LOGsx("dequeue",dequeue(S1,S2));
    LOGsx("dequeue",dequeue(S1,S2));
    printStacks(S1,S2);
    LOGsx("dequeue",dequeue(S1,S2));
    printStacks(S1,S2);
    LOGsx("dequeue",dequeue(S1,S2));
    printStacks(S1,S2);
    LOGsx("dequeue",dequeue(S1,S2));
    printStacks(S1,S2);

    return 0;
}