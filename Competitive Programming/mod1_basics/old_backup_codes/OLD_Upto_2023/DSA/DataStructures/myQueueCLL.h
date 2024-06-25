#pragma once
#ifndef MYQUEUECLL_H
#define MYQUEUECLL_H

typedef struct CQLLnode{ int data; struct CQLLnode * next; } CQLLNode;
CQLLNode* CQLLcreateNode(int d);
typedef struct CLLQueue { CQLLNode* ptr;} QUEUE;
QUEUE* createQUEUE();
QUEUE* insertQUEUE(QUEUE* q,int d);
int isQUEUEempty(QUEUE *q);
int deleteQUEUE(QUEUE* q);

#endif 