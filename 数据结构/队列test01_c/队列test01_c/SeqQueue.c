#include "SeqQueue.h"

void InitQueue(SeqQueue* q)
{
	q->front = 0;
	q->rear = 0;
	q->tag = 0;
}

int QueueEmpty(SeqQueue* q)
{
	if (q->rear == q->front && q->tag==0)
	{
		return 1;
	}

	return 0;
}

int EnterQueue(SeqQueue* q, DataType* x)
{
	//if (q->rear == QUEUESIZE&&q->tag == 1)
	q->rear = q->rear % QUEUESIZE;
	q->front = q->front % QUEUESIZE;
	if(q->rear == q->front && q->tag == 1)
	{
		return 0;
	}

	q->tag = 1;
	q->data[q->rear] = *x;
	q->rear = (q->rear + 1) % QUEUESIZE;

	return 1;
}

int DeleteQueue(SeqQueue* q, DataType* x)
{
	if (q->rear == q->front && q->tag == 0)
	{
		return 0;
	}

	q->tag = 0;
	*x = q->data[q->front];
	q->front = (q->front + 1) % QUEUESIZE;
	return 1;
}

int GetQueueHead(SeqQueue* q, DataType* x)
{
	if (q->rear == q->front && q->tag == 0)
	{
		return 0;
	}

	*x = q->data[q->front];
	return 1;
}

//int GetSize(SeqQueue* q)
//{
//	return q->rear - q->front;
//}
