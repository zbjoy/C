#pragma once

#include <stdio.h>

#define QUEUESIZE 5

typedef int DataType;
typedef struct
{
	DataType data[QUEUESIZE];
	int front;
	int rear;
	int tag;
}SeqQueue;

void InitQueue(SeqQueue* q);

int QueueEmpty(SeqQueue* q);

int EnterQueue(SeqQueue* q, DataType* x);

int DeleteQueue(SeqQueue* q, DataType* x);

int GetQueueHead(SeqQueue* q, DataType* x);

int GetSize(SeqQueue* q);
