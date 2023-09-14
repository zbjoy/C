#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <stdio.h>
#include "labyrinth.h"

#endif

#define STACKSIZE 100

//typedef PathType DataType;
//typedef int DataType;
typedef struct
{
	PathType data[STACKSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack* s);

int StackEmpty(SeqStack* s);

int Push_Stack(SeqStack* s, PathType* x);

int Pop_Stack(SeqStack* s, PathType* x);

int GetTop(SeqStack* s, PathType* x);
