#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "CircularQueue.h"

int main()
{
	CircularQueue q;
	Init_Queue(&q);
	int i = 7;
	for (; i < 17; i++)
	{
		Enter_Queue(&q, &i);
	}

	int j = 0;
	for (; j < 10; j++)
	{
		Delete_Queue(&q, &i);
		printf("%d ", i);
	}
	return 0;
}