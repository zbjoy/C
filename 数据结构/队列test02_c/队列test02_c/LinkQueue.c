#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkQueue.h"

void InitQueue(LinkQueue* q)
{
	LQNode* s = (LQNode*)malloc(sizeof(LQNode));
	q->front = q->rear = s;
	s->next = NULL;
}

int EnQueue(LinkQueue* q, DataType x)
{
	LQNode* s = (LQNode*)malloc(sizeof(LQNode));
	if (s == NULL)
	{
		return 0;
	}

	s->data = x;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;//q->rear = s;
	return 1;
}

int QueueEmpty(LinkQueue* q)
{
	if (q->rear == q->front)
	{
		return 1;
	}

	return 0;
}

int DeQueue(LinkQueue* q, DataType* px)
{
	LQNode* s;
	if (QueueEmpty == 1)
	{
		return 0;
	}

	s = q->front->next;
	q->front->next = s->next;
	*px = s->data;
	free(s);
	//s = NULL;
	if (q->front->next == NULL)
	{
		q->front = q->rear;
	}

	return 1;
}

int GetQueueHead(LinkQueue* q, DataType* px)
{
	if (q->rear == q->front)
	{
		return 0;
	}

	*px = q->front->next->data;
	return 1;
}