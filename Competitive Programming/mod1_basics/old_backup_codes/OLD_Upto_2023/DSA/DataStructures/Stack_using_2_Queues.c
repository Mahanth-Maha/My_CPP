#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));

#define N 5
typedef struct St { int *s, front, rear;} Queue;

Queue* initQueue(){
    Queue *Q = malloc(sizeof(Queue));
    Q->s = malloc(sizeof(int)*N); 
    for(int i = 0 ; i < N ; i ++) Q->s[i] = 0;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}
void enqueue(Queue *Q,int d) {
    if((Q->rear +1) %N != Q->front){
        if(Q->front == -1) Q->front = 0;
        Q->rear = Q->rear + 1 % N;
        Q->s[Q->rear] = d;
    }
}
int dequeue(Queue *Q){ 
    int d= -1;
    if(Q->front != -1){
        d = Q->s[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = Q->front +1 % N;
    }
    return d;
}

int getSize(Queue *Q){ 
    if(Q->front == -1) return 0;
    if(Q->front > Q->rear) return N - Q->front + Q->rear + 1;
    return Q->rear - Q->front + 1;
}

void printQueues(Queue *Q1,Queue *Q2){
    printf("Q1 : ");
    for(int i = 0 ;i < N; i++) printf("%5d",Q1->s[i]);
    printf("\nQ2 : ");
    for(int i = 0 ;i < N; i++) printf("%5d",Q2->s[i]);
    printf("\n");
}

void PUSH(Queue *Q1, Queue *Q2,int d) {
    enqueue(Q1,d);
}
int POP(Queue *Q1, Queue *Q2){ 
    int d = -1;
    int k = getSize(Q1);
    if(k <= 1) 
        return dequeue(Q1);
    k--;
    while(k--)
        enqueue(Q2,dequeue(Q1));
    int ret = dequeue(Q1);
    while((d = dequeue(Q2)) != -1)
        enqueue(Q1,d);
    return ret;
}

int main(int argc, char const *argv[])
{
    Queue *Q1 = initQueue(),*Q2 = initQueue();
    PUSH(Q1,Q2,10);
    printf("Push %d\n",10);
    PUSH(Q1,Q2,20);
    printf("Push %d\n",20);
    PUSH(Q1,Q2,30);
    printf("Push %d\n",30);
    LOGsx("POP",POP(Q1,Q2));
    PUSH(Q1,Q2,40);
    printf("Push %d\n",40);
    PUSH(Q1,Q2,50);
    printf("Push %d\n",50);
    LOGsx("POP",POP(Q1,Q2));
    PUSH(Q1,Q2,60);
    printf("Push %d\n",60);
    printQueues(Q1,Q2);
    PUSH(Q1,Q2,70);
    printf("Push %d\n",70);
    printQueues(Q1,Q2);
    PUSH(Q1,Q2,80);
    printf("Push %d\n",80);
    printQueues(Q1,Q2);
    PUSH(Q1,Q2,90);
    printf("Push %d\n",90);
    LOGsx("POP",POP(Q1,Q2));
    LOGsx("POP",POP(Q1,Q2));
    LOGsx("POP",POP(Q1,Q2));
    LOGsx("POP",POP(Q1,Q2));
    LOGsx("POP",POP(Q1,Q2));
    printQueues(Q1,Q2);
    LOGsx("POP",POP(Q1,Q2));
    printQueues(Q1,Q2);
    LOGsx("POP",POP(Q1,Q2));
    printQueues(Q1,Q2);
    LOGsx("POP",POP(Q1,Q2));
    printQueues(Q1,Q2);

    return 0;
}