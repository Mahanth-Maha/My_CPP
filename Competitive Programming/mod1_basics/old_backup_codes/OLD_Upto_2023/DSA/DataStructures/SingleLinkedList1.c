#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(x) printf("%d\n",(x));
#define LOGS(s,x) printf("%s : %d\n",(s),(x));

typedef struct SLnode { int data; struct SLnode * next; } SLNode;
typedef struct DLnode { int data; struct DLnode * prev; struct DLnode * next;} DLNode;
typedef struct Tnode { int data; struct Tnode * left; struct Tnode * right;} TNode;

int isEmpty(struct SLnode *p){
    // if(p == NULL)
    //     return 1;
    // return 0;
    return (p)? 0 : 1;
}

int isSingleNode(struct SLnode *p){
    // if(p!=NULL && p->next == NULL)
    //     return 1;
    // return 0;
    return (p && !p->next)? 1: 0;
}

int SLLlength(struct SLnode *p){
    int i = 0;
    while(p){
        p = p->next;
        i++;
    }
    return i;
}

void SLLPrint(struct SLnode *p){
    printf("DATA : ");
    while(p){
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct SLnode* insertAtBegin(struct SLnode * head,int data){
    struct SLnode * q = malloc(sizeof(*q)) , *p= head;
    q->data = data;
    q->next = p;
    p = q;
    return p;
}

struct SLnode* insertAtEnd(struct SLnode * head,int data){
    struct SLnode * q = malloc(sizeof(*q)) , *p = head;
    q->data = data;
    q->next= NULL;
    if(!p)
        return q;
    while(p->next){p = p->next;}
    q->next = p->next;
    p->next = q;
    return head;
}

struct SLnode* insertAfterData(struct SLnode * head,int data,int Afterdata){
    struct SLnode * q = malloc(sizeof(*q)) , *p = head;
    q->data = data;
    while(p && p->data != Afterdata){p = p->next;}
    if(!p) return head;
    q->next = p->next;
    p->next = q;
    return head;
}

void deleteBegin(struct SLnode ** head){
    if(*head){
        struct SLnode * p = *head;
        *head = (*head)->next;
        free(p);
    }
}

void deleteEnd(struct SLnode ** head){
    if(!(*head)) return ;
    struct SLnode *p = *head, *q;
    if(!p->next) {
        free(p);
        *head = NULL;
        return;
    }
    while(p->next->next){p = p->next;}
    q = p->next;
    p->next = NULL;
    free(q);
}

void deleteAfterData(struct SLnode ** head,int Afterdata){
    if(!*head || !(*head)->next) return;
    struct SLnode * p = *head, *q;
    while(p && p->data != Afterdata){p = p->next;}
    q = p->next;
    p->next = q->next;
    free(q);
}

void printSL_rec(struct SLnode * p){
    if(p){
        printf("%d -> ",p->data);
        printSL_rec(p->next);
    }
}

void printSL_rec_Rev(struct SLnode * p){
    if(p){
        printSL_rec_Rev(p->next);
        printf("<- %d",p->data);
    }
}

int SL_sum(struct SLnode * p){
    if(p)
        return SL_sum(p->next)+ p->data;
    return 0;
}

int SL_len(struct SLnode * p){
    if(p)
        return SL_len(p->next)+ 1;
    return 0;
}


int main(int argc, char const *argv[])
{
    struct SLnode *head = NULL,*p;
    LOGS("Empty", isEmpty(head));
    LOGS("1 Elem ",isSingleNode(head));
    head = malloc(sizeof(*head));
    head->data = 10;
    head->next = NULL;
    p = head;
    LOGS("Empty", isEmpty(p));
    LOGS("1 Elem ",isSingleNode(p));
    LOGS("Length",(SLLlength(p)));
    SLNode* q = malloc(sizeof(*head));
    q->data = 20;
    q->next = NULL;
    p->next = q;
    LOGS("Empty", isEmpty(p));
    LOGS("1 Elem ",isSingleNode(p));
    LOGS("Length",(SLLlength(p)));

    SLLPrint(head);
    head = insertAtBegin(head,5);
    SLLPrint(head);
    head = insertAtEnd(head,25);
    SLLPrint(head);
    head = insertAfterData(head,15,10);
    SLLPrint(head);
    head = insertAfterData(head,35,25);
    SLLPrint(head);
    head = insertAfterData(head,12,5);
    SLLPrint(head);
    head = insertAfterData(head,13,100);
    SLLPrint(head);
    struct SLnode *head2 = NULL,*p2;
    head2 = insertAtEnd(head2,200);
    SLLPrint(head2);

    printf("LL :");
    printSL_rec(head);
    printf("\n");
    printf("Rev LL :");
    printSL_rec_Rev(head);
    printf("\n");

    LOGS("DELETING",0);
    deleteBegin(&head);
    SLLPrint(head);
    deleteEnd(&head2);
    SLLPrint(head2);
    deleteEnd(&head2);
    SLLPrint(head2);
    deleteEnd(&head);
    SLLPrint(head);
    deleteEnd(&head);
    SLLPrint(head);
    deleteAfterData(&head,10);
    SLLPrint(head);
    deleteAfterData(&head,12);
    SLLPrint(head);
    deleteAfterData(&head,12);
    SLLPrint(head);
    deleteAfterData(&head,12);
    SLLPrint(head);

    LOGS("SUM ",SL_sum(head));
    LOGS("SUM ",SL_sum(head2));
    LOGS("LEN ",SL_len(head));
    LOGS("LEN ",SL_len(head2));

    return 0;
}