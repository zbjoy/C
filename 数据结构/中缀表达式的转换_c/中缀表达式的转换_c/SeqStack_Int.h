#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>

enum
{
	DATAMAX_INT = 10
};

typedef float DataType_INT;
typedef struct
{
	DataType_INT data[DATAMAX_INT];
	int top;
}SeqStack_Int;//OP;//SeqStack;

void Init_SeqStack_Int(SeqStack_Int* s);

int Push_SeqStack_Int(SeqStack_Int* s, DataType_INT* px);

int Pop_SeqStack_Int(SeqStack_Int* s, DataType_INT* px);

int GetTop_SeqStack_Int(SeqStack_Int* s, DataType_INT* px);

int Empty_SeqStack_Int(SeqStack_Int* s);