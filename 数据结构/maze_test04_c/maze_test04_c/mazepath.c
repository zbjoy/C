#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include "mazepath.h"

void MazePath(int maze[8][10], Item move[], SeqStack* s)
{
	PathType temp;
	PathType t;
	temp.x = 1;
	temp.y = 1;
	temp.d = 1;
	Push_SeqStack(s, &temp);
	int x = 0;
	int y = 0;

	//PathType obj = { 7,9,1 };
	maze[1][1] = 1;

	while (1)
	{
		int i = 0;
		temp.d = 0;
		for (; i < 8; i++)
		{
			x = temp.x + move[i].x;
			y = temp.y + move[i].y;
			if (maze[y][x] == 0)
			{
				temp.x = x;
				temp.y = y;
				temp.d = 1;
				maze[y][x] = 1;
				Push_SeqStack(s, &temp);
				break;
			}
		}

		if (i == 8 && temp.d == 0)
		{
			//Pop_SeqStack(s, &temp);
			Pop_SeqStack(s, &t);
			GetTop_SeqStack(s, &temp);
		}
		
		if (y == 6 && x == 8)
		{
			break;
		}
	}
}