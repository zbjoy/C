#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include "SeqStack.h"
#include "maze.h"

//int maze[ROW + 2][COL + 2] = {
//								{ 1,1,1,1,1,1,1,1,1,1 },
//								{ 1,0,1,1,1,0,1,1,1,1 },
//								{ 1,1,0,1,0,1,1,1,1,1 },
//								{ 1,0,1,0,0,0,0,0,1,1 },
//								{ 1,0,1,1,1,0,1,1,1,1 },
//								{ 1,1,0,0,1,1,0,0,0,1 },
//								{ 1,0,1,1,0,0,1,1,0,1 },
//								{ 1,1,1,1,1,1,1,1,1,1 }
//};

Item move[8] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };

void MazePath(int maze[ROW+2][COL+2],Item move[8],SeqStack* s)
{
	Path temp;
	int x = 1;
	int y = 1;
	temp.x = x;
	temp.y = y;
	Push_Stack(s, &temp);
	maze[x][y] = -1;
	int i = 0;
	while (!(x == 6 && y == 8))
	{
		int image = 1;
		for (i = 0; i < 8; i++)
		{
			x = temp.x;
			y = temp.y;
			//x = move[i].x;
			x = x + move[i].x;
			//y = move[i].y;
			y = y + move[i].y;
			if (maze[x][y] == 0)
			{
				temp.x = x;
				temp.y = y;
				//temp.d = -1;
				//maze[x][y] = -1;
				maze[x][y] = -1;
				Push_Stack(s, &temp);
				image = 0;
				break;
			}
		}

		//if (maze[x][y] == -1 && x != 6 || y != 8)
		//if (!(temp.x != x || temp.y != y))
		Path t;

		GetTop_Stack(s, &t);
		//if (!(t.x == temp.x && t.y == temp.y))
		if(image == 1)
		{
			Pop_Stack(s, &temp);
			GetTop_Stack(s, &temp);
		}
	}
	
}

int main()
{
	int maze[ROW + 2][COL + 2] = {
								{ 1,1,1,1,1,1,1,1,1,1 },
								{ 1,0,1,1,1,0,1,1,1,1 },
								{ 1,1,0,1,0,1,1,1,1,1 },
								{ 1,0,1,0,0,0,0,0,1,1 },
								{ 1,0,1,1,1,0,1,1,1,1 },
								{ 1,1,0,0,1,1,0,0,0,1 },
								{ 1,0,1,1,0,0,1,1,0,1 },
								{ 1,1,1,1,1,1,1,1,1,1 }
								};
	SeqStack s;
	Init_Stack(&s);
	MazePath(maze, move, &s);
	SeqStack temp;
	Init_Stack(&temp);
	while (!Empty_Stack(&s))
	{
		Path t;
		Pop_Stack(&s, &t);
		Push_Stack(&temp, &t);
	}

	while (!Empty_Stack(&temp))
	{
		Path t;
		Pop_Stack(&temp, &t);
		printf("-->(%d,%d)", t.x, t.y);
	}
	
	return 0;
}