#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include "pathtype.h"

#define ROW 6
#define COL 8

int maze[ROW + 2][COL + 2] = {
	{1,1,1,1,1,1,1,1,1,1}
	,{1,0,1,1,1,0,1,1,1,1}
	,{1,1,0,1,0,1,1,1,1,1}
	,{1,0,1,0,0,0,0,0,1,1}
	,{1,0,1,1,1,0,1,1,1,1}
	,{1,1,0,0,1,1,0,0,0,1}
	,{1,0,1,1,0,0,1,1,0,1}
	,{1,1,1,1,1,1,1,1,1,1}
};

