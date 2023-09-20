#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

void Init_Queue(CircularQueue* q)
{
	q->front = q->rear = 0;
}

int Enter_Queue(CircularQueue* q, DataType* px)
{
	//if (q->front == q->rear+1)
	if(q->front == (q->rear + 1) % DATAMAX)
	{
		return 0;
	}

	q->data[q->rear] = *px;
	q->rear = (q->rear + 1) % DATAMAX;
	return 1;
}

int Delete_Queue(CircularQueue* q, DataType* px)
{
	if (q->front == q->rear)
	{
		return 0;
	}

	*px = q->data[q->front];

	//if (q->rear == 0)
	//{
	//	q->rear = DATAMAX - 1;
	//}
	//else
	//{
	//	q->rear--;
	//}

	q->front = (q->front + 1) % DATAMAX;
	return 1;
}

int Empty_Queue(CircularQueue* q)
{
	if (q->rear == q->front)
	{
		return 1;
	}

	return 0;
}

int GetHead_Queue(CircularQueue* q,DataType* px)
{
	if (Empty_Queue(q))
	{
		return 0;
	}

	*px = q->data[q->front];
	return 1;
}