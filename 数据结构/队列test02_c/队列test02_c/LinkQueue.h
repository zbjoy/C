#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node
{
	DataType data;
	struct node* next;
}LQNode;

typedef struct
{
	LQNode* front;
	LQNode* rear;
}LinkQueue;

void InitQueue(LinkQueue* q);

int EnQueue(LinkQueue* q, DataType x);

int QueueEmpty(LinkQueue* q);

int DeQueue(LinkQueue* q, DataType* px);

int GetQueueHead(LinkQueue* q, DataType* px);