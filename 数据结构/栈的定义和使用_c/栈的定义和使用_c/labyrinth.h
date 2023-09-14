#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __LABYRINTH_H__
#define __LABYRINTH_H__

#include <stdio.h>
//#include "myStack.h"

#endif

#define ROW 6
#define COL 8

typedef struct PathType
{
	int x;
	int y;
	int d;
}PathType;


typedef struct Item
{
	int x;
	int y;
}Item;


//为什么不能在这里声明
//int maze[ROW + 2][COL + 2] = {
//								{1,1,1,1,1,1,1,1,1,1},
//								{1,0,1,1,1,0,1,1,1,1},
//								{1,1,0,1,0,1,1,1,1,1},
//								{1,0,1,0,0,0,0,0,1,1},
//								{1,0,1,1,1,0,1,1,1,1},
//								{1,1,0,0,1,1,0,0,0,1},
//								{1,0,1,1,0,0,1,1,0,1},
//								{1,1,1,1,1,1,1,1,1,1}
//};
//
//Item move[8] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };