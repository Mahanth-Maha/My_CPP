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
static int Q[N] , front = -1,rear = -1;

void enqueue(int d) {
    if((rear+1)%N != front) {
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1) %N;
        Q[rear] = d;
    }
}
int dequeue(){ 
    int t = -1;
    if(front != -1){
        t = Q[front];
        Q[front] = 0;
        if(front == rear)
            front = rear = -1;
        else
            front = ++front % N;
    }
    return t;
}

int getSize(){
    // if(front == rear && front != -1) return 1;
    if(front == -1) return 0;
    if(front > rear) return N - (front - rear - 1);
    // if(front < rear) 
        return rear - front + 1;
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
    LOGsx("Size ",getSize());
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);
    enqueue(50);
    p(Q);
    LOGsx("Size ",getSize());
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);
    enqueue(60);
    p(Q);
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);
    LOGsx("dequeue",dequeue());
    LOGsx("Size ",getSize());
    p(Q);

    return 0;
}

/* code from chatgpt

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}

int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(CircularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
}

int dequeue(CircularQueue *queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // You may choose a different value to indicate an error.
    }
    element = queue->data[queue->front];
    if (queue->front == queue->rear) {
        // Last element in the queue is being dequeued
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return element;
}


*/