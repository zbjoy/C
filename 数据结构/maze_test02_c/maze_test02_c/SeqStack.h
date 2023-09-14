#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>

#include "maze.h"

#define DATAMAX 100

typedef Path DataType;
typedef struct
{
	DataType data[DATAMAX];
	int top;
}SeqStack;

void Init_Stack(SeqStack* s);

int Push_Stack(SeqStack* s, DataType* x);

int Pop_Stack(SeqStack* s,DataType* x);

int Empty_Stack(SeqStack* s);

int GetTop_Stack(SeqStack* s, DataType* x);