#define _CRT_SECURE_NO_WARNINGS 1

#include "myStack.h"

void InitStack(SeqStack* s)
{
	s->top = -1;
}

int StackEmpty(SeqStack* s)
{
	if (s->top == -1)
	{
		return 1;
	}

	return 0;
}

int Push_Stack(SeqStack* s, PathType* x)
{
	if (s->top == STACKSIZE - 1)
	{
		printf("Õ»ÒÑÂú");
		return 0;
	}

	s->top++;
	s->data[s->top] = *x;
	return 1;
}

int Pop_Stack(SeqStack* s, PathType* x)
{
	if (s->top == -1)
	{
		printf("Õ»¿Õ");
		return 0;
	}

	*x = s->data[s->top];
	s->top--;
	return 1;
}

int GetTop(SeqStack* s, PathType* x)
{
	if (s->top == -1)
	{
		printf("Õ»¿Õ");
		return 0;
	}

	*x = s->data[s->top];
	return 1;
}