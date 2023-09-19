#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

int main()
{
	LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(q);
	int i = 7;
	for (; i < 17; i++)
	{
		EnQueue(q, i);
	}

	int j = 0;
	for (; j < 10; j++)
	{
		DeQueue(q, &i);
		printf("%d ", i);
	}

	return 0;
}