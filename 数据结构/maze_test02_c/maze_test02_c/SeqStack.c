#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include "SeqStack.h"


void Init_Stack(SeqStack* s)
{
	//s->top = 0;
	s->top = -1;
}

int Push_Stack(SeqStack* s, DataType* x)
{
	//if (s->top == DATAMAX)
	if(s->top == DATAMAX - 1)
	{
		return 0;
	}
	//s->data[s->top] = *x;
	//s->top++;

	s->top++;
	s->data[s->top] = *x;
	return 1;
}

int Pop_Stack(SeqStack* s, DataType* x)
{
	//if (s->top == 0)
	if(s->top == -1)
	{
		return 0;
	}
	*x = s->data[s->top];
	s->top--;
	return 1;
}

int Empty_Stack(SeqStack* s)
{
	//if (s->top == 0)
	if(s->top == -1)
	{
		return 1;
	}

	return 0;
}

int GetTop_Stack(SeqStack* s, DataType* x)
{
	//if (s->top == 0)
	if(s->top == -1)
	{
		return 0;
	}

	*x = s->data[s->top];
	return 1;
}

