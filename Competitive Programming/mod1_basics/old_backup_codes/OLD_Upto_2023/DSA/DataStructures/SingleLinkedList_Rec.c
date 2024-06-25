#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n", (x));
#define LOGs(x) printf("%s\n", (x));
#define LOGsx(s, x) printf("%s : %d\n", (s), (x));

typedef struct SLnode{
    int data;
    struct SLnode *next;
} Node;

Node *createNode(int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node *createListFromArray(int arr[], int arraySize){
    Node *rootNodePtr = createNode(arr[0]);
    Node *lastNodePtr = rootNodePtr;

    for (int i = 1; i < arraySize; i++)
    {
        Node *nodePtr = createNode(arr[i]);
        lastNodePtr->next = nodePtr;
        lastNodePtr = lastNodePtr->next;
    }
    return rootNodePtr;
}
Node *insertAtBegin(Node *head, int data){
    Node *q = malloc(sizeof(*q)), *p = head;
    q->data = data;
    q->next = p;
    p = q;
    return p;
}

Node *insertAtEnd(Node *head, int data){
    Node *q = malloc(sizeof(*q)), *p = head;
    q->data = data;
    q->next = NULL;
    if (!p)
        return q;
    while (p->next)
    {
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
    return head;
}

Node *insertAfterData(Node *head, int data, int Afterdata){
    Node *q = malloc(sizeof(*q)), *p = head;
    q->data = data;
    while (p && p->data != Afterdata)
    {
        p = p->next;
    }
    if (!p)
        return head;
    q->next = p->next;
    p->next = q;
    return head;
}

void deleteBegin(Node **head){
    if (*head)
    {
        Node *p = *head;
        *head = (*head)->next;
        free(p);
    }
}

void deleteEnd(Node **head)
{
    if (!(*head))
        return;
    Node *p = *head, *q;
    if (!p->next)
    {
        free(p);
        *head = NULL;
        return;
    }
    while (p->next->next)
    {
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    free(q);
}

void deleteAfterData(Node **head, int Afterdata)
{
    if (!*head || !(*head)->next)
        return;
    Node *p = *head, *q;
    while (p && p->data != Afterdata)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}

void print(Node *p)
{
    if (p)
    {
        printf("%d -> ", p->data);
        print(p->next);
    }
}

void p(Node *n){
    printf("Data : ");
    print(n);
    printf("NULL\n");
}

void print_Rev(Node *p)
{
    if (p)
    {
        print_Rev(p->next);
        printf("<- %d", p->data);
    }
}

int sum(Node *p)
{
    if (p)
        return sum(p->next) + p->data;
    return 0;
}

int len(Node *p)
{
    if (p)
        return len(p->next) + 1;
    return 0;
}

void insertRear(Node ** head, int d){
    if(!(*head)){
        *head = createNode(d);
        return;
    } 
    insertRear(& ((*head)->next),d);
}

Node * reverse(Node * head){
    if(!head || !head->next) return head;
    Node *res = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}

Node * reverse2(Node * head,Node * prev){
    // if(!head) return head;
    // if(!head->next){
    //     head->next = prev;
    //     return head;
    // }
    // Node *res = reverse2(head->next,head);
    // head->next = prev;
    // return res;
    if(!head) return prev;
    Node *res = reverse2(head->next,head);
    head->next = prev;
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Node * head = createListFromArray(arr, sizeof(arr) / sizeof(int));
    LOGsx("Len",len(head));
    LOGsx("Sum",sum(head));
    LOGs("Data :");
    print(head);
    LOGs("\nData :")
    print_Rev(head);
    LOGs("");
    insertRear(&head,11);
    p(head);
    insertRear(&head,12);
    p(head);
    head = reverse(head);
    p(head);
    head = reverse2(head,NULL);
    p(head);
    int len = 0;
    for(Node * q = head; q!=NULL;q = q->next,len++);
    LOGsx("Len",len);

    return 0;
}