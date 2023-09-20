#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define DATAMAX 5

typedef int DataType;
typedef struct
{
	DataType data[DATAMAX];
	int front;
	int rear;
}CircularQueue;

void Init_Queue(CircularQueue* q);

int Enter_Queue(CircularQueue* q,DataType* px);

int Delete_Queue(CircularQueue* q, DataType* px);

int Empty_Queue(CircularQueue* q);

int GetHead_Queue(CircularQueue* q,DataType* px);