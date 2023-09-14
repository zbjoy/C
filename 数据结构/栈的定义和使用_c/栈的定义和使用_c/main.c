#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "myStack.h"
//#include "labyrinth.h"为什么就会重定义



void MazePath(int maze[ROW + 2][COL + 2], Item move[8], SeqStack* s)
{
	int x;
	int y;
	int d;
	PathType temp;
	temp.x = 1;
	temp.y = 1;

	Push_Stack(s, &temp);
	maze[temp.x][temp.y] = -1;
	int dd = 0;
	int i = 0;
	int j = 0;
	while (!StackEmpty(s))
	{
		GetTop(s, &temp);
		x = temp.x;
		y = temp.y;
		d = dd;
		while (d < 8)
		{
			i = x + move[d].x;
			j = y + move[d].y;
			if (maze[i][j] == 0)
			{
				temp.x = i;
				temp.y = j;
				temp.d = d;
				Push_Stack(s, &temp);
				dd = 0;
				maze[i][j] = -1;
				if (i == ROW && j == COL)
				{
					return;
				}
				break;
			}
			else
			{
				d = d + 1;
			}
			if (d == 8)
			{
				Pop_Stack(s, &temp);
				dd = temp.d + 1;
			}
		}
	}

}

int main()
{
	int maze[ROW + 2][COL + 2] = {
								{1,1,1,1,1,1,1,1,1,1},
								{1,0,1,1,1,0,1,1,1,1},
								{1,1,0,1,0,1,1,1,1,1},
								{1,0,1,0,0,0,0,0,1,1},
								{1,0,1,1,1,0,1,1,1,1},
								{1,1,0,0,1,1,0,0,0,1},
								{1,0,1,1,0,0,1,1,0,1},
								{1,1,1,1,1,1,1,1,1,1}
	};

	Item move[8] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };

	SeqStack sq;
	InitStack(&sq);

	MazePath(maze, move, &sq);

	SeqStack t;
	InitStack(&t);

	PathType temp;
	while (!StackEmpty(&sq))
	{

		Pop_Stack(&sq, &temp);
		Push_Stack(&t, &temp);
	}

	printf("迷宫顺序为：");
	while (!StackEmpty(&t))
	{
		PathType p;
		Pop_Stack(&t, &p);
		int x = p.x;
		int y = p.y;
		printf("-->(%d,%d)", x, y);
	}

	return 0;
}