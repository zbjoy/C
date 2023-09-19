#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "SeqQueue.h"

int main()
{
	SeqQueue q;
	InitQueue(&q);
	int i = 0;
	for (; i < 5; i++)
	{
		EnterQueue(&q, &i);
	}

	int x = 10;
	GetQueueHead(&q, &x);

	//int j = GetSize(&q);

	int ret = EnterQueue(&q, &x);

	DeleteQueue(&q, &x);

	x = 10;

	int ret2 = EnterQueue(&q, &x);

	printf("ret2 = %d ", ret2);

	for (i = 0; i < 6; i++)
	{
		DeleteQueue(&q, &x);
		printf("%d  ", x);
	}


	return 0;
}
