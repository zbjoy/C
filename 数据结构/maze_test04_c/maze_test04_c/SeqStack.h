#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>

#include "pathtype.h"

#define DATASIZE 100

typedef PathType DataType;
typedef struct
{
	DataType data[DATASIZE];
	int top;
}SeqStack;

void Init_SeqStack(SeqStack* s);

int Push_SeqStack(SeqStack* s, DataType* px);

int Pop_SeqStack(SeqStack* s, DataType* px);

int Empty_SeqStack(SeqStack* s);

int GetTop_SeqStack(SeqStack* s,DataType* px);
