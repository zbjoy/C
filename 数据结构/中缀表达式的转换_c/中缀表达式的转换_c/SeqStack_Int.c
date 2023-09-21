#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqStack_Int.h"

#include "SeqStack.h"

void Init_SeqStack_Int(SeqStack_Int* s)
{
	s->top = -1;
}

int Push_SeqStack_Int(SeqStack_Int* s, DataType_INT* px)
{
	if (s->top == DATAMAX_INT - 1)
	{
		return 0;
	}

	s->top++;
	s->data[s->top] = *px;
	return 1;
}

int Pop_SeqStack_Int(SeqStack_Int* s, DataType_INT* px)
{
	if (Empty_SeqStack_Int(s))
	{
		return 0;
	}

	*px = s->data[s->top];
	s->top--;
	return 1;
}

int GetTop_SeqStack_Int(SeqStack_Int* s, DataType_INT* px)
{
	if (Empty_SeqStack_Int(s))
	{
		return 0;
	}

	*px = s->data[s->top];
	return 1;
}

int Empty_SeqStack_Int(SeqStack_Int* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	return 0;
}