#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
//#include "pathtype.h"
#include "SeqStack.h"

//extern move[8];

//void MazePath(int* maze[],)
void MazePath(int maze[8][10], Item move[], SeqStack* s);