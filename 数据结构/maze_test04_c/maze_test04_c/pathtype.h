#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __PATHTYPE_H__
#define __PATHTYPE_H__
#pragma once

#include <stdio.h>

typedef struct
{
	int x;
	int y;
	int d;
}PathType;

typedef struct
{
	int x;
	int y;
}Item;


#ifndef __MOVE__
#define __MOVE__
//Item move[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
Item move[8];

#endif

#endif