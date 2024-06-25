#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));


typedef struct CQLLnode{ int data; struct CQLLnode * next; } CQLLNode;

CQLLNode* CQLLcreateNode(int d){
    CQLLNode * s = malloc(sizeof(CQLLNode));
    s->data = d;
    s->next = s;
    return s;
}

typedef struct CLLQueue { CQLLNode* ptr;} QUEUE;

QUEUE* createQUEUE(){
    QUEUE *q = malloc(sizeof(QUEUE));
    q->ptr = NULL;
    return q;
}

QUEUE* insertQUEUE(QUEUE* q,int d){
    if(!q) return NULL;
    if(!q->ptr) {
        q->ptr = CQLLcreateNode(d);
    } else {
        CQLLNode * t = CQLLcreateNode(d);
        t->next = q->ptr->next;
        q->ptr->next = t;
        q->ptr = t;
    }
    return q;
}

int isQUEUEempty(QUEUE *q){
    return (q->ptr == NULL) ;
}

int deleteQUEUE(QUEUE* q){
    if(!q) return -1;
    if(!q->ptr) return -1;
    int d = -1;
    if(q->ptr->next == q->ptr){ 
        d = q->ptr->data;
        free(q->ptr);
        q->ptr = NULL;
    } else {    
        CQLLNode * t = q->ptr->next ;
        d = t->data;
        q->ptr->next = t->next;
        free(t);
    }
    return d;
}

int main(int argc, char const *argv[])
{
    QUEUE * queue = createQUEUE();
    int arr[] = { 10,85,15,70,20,60,30, -1};
    int *p = arr;
    while(*p != -1){
        queue = insertQUEUE(queue, *p);
        p++;
    }
    while(!isQUEUEempty(queue)){
        LOGsx("dequeued",deleteQUEUE(queue))
    }
    LOGsx("dequeued",deleteQUEUE(queue))

    return 0;
}