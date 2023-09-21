#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>

enum
{
	DATAMAX = 10
};

typedef char DataType;
typedef struct
{
	DataType data[DATAMAX];
	int top;
}SeqStack;//OP;//SeqStack;

void Init_SeqStack(SeqStack* s);

int Push_SeqStack(SeqStack* s, DataType* px);

int Pop_SeqStack(SeqStack* s, DataType* px);

int GetTop_SeqStack(SeqStack* s, DataType* px);

int Empty_SeqStack(SeqStack* s);

//void Init_SeqStack(OP* s);
//
//int Push_SeqStack(OP* s, DataType* px);
//
//int Pop_SeqStack(OP* s, DataType* px);
//
//int GetTop_SeqStack(OP* s, DataType* px);
//
//int Empty_SeqStack(OP* s);