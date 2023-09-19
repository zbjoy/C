#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "data.h"
#include "mazepath.h"
#include "SeqStack.h"

int main()
{
	SeqStack s;
	SeqStack s1;
	Init_SeqStack(&s);
	Init_SeqStack(&s1);
	MazePath(maze, move, &s);

	PathType temp;

	while (!Empty_SeqStack(&s))
	{
		Pop_SeqStack(&s, &temp);
		//printf("-->(%d,%d)", temp.x, temp.y);
		Push_SeqStack(&s1, &temp);
	}

	while (!Empty_SeqStack(&s1))
	{
		Pop_SeqStack(&s1, &temp);
		printf("-->(%d,%d)", temp.x, temp.y);
	}
	return 0;
}