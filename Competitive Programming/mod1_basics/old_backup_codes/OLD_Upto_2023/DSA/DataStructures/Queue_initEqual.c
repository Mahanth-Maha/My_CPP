#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));

#define N 5
void p(int *a){ 
    printf("Data :");
    for (int i = 0 ; i < N;i++)
        printf("%5d",a[i]);
    LOGs("");
}
static int Q[N] , front = 0,rear = 0;

void enqueue(int d) {
    if((rear+1)%N != front){ 
        Q[rear++] = d ;
        rear %= N;
    }
}
int dequeue(){ 
    int t = -1;
    if(front != rear){
        t = Q[front++];
        Q[front-1] = 0;
        front %= N;
    }
    return t;
}

int main(int argc, char const *argv[])
{
    enqueue(10);
    p(Q);
    enqueue(20);
    p(Q);
    enqueue(30);
    p(Q);
    enqueue(40);
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);
    enqueue(50);
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);
    enqueue(60);
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);
    LOGsx("dequeue",dequeue());
    p(Q);

    return 0;
}