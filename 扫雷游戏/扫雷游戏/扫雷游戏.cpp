#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#define ROW 25
#define COL 20
#define NUM 50
#define SIZE 30
int count = 0;
int map[ROW + 2][COL + 2];
IMAGE img[12];
void GameInit()
{
	srand((unsigned int)time(NULL));//随机数种子
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			map[i][j] = 0;
		}
	}
	int n = NUM;
	while (n)
	{
		int i = rand() % ROW+1;
		int j = rand() % COL+1;
		if (map[i][j] == 0)
		{
			map[i][j] = -1;
			n--;
		}
	}
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (map[i][j] == 0)
			{
				for (int r = i - 1; r <= i + 1; r++)
				{
					for (int c = j - 1; c <= j + 1; c++)
					{
						if (map[r][c] == -1)
						{
							map[i][j] += 1;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 0; j <= COL; j++)
		{
			map[i][j] += 20;
		}
	}
}
void Gamedraw()
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			printf("%2d ",map[i][j]);
			if (map[i][j] == -1)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[9]);
			}
			else if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[10]);
			}
			else if(map[i][j]>=30)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[11]);
			}
		}
		printf("\n");
	}
}
void OpenZero(int i,int j)
{
	map[i][j] -= 20;
	count++;
	for (int r = i - 1; r <= i + 1; r++)
	{
		for (int c = j - 1; c <= j + 1; c++)
		{
			if(r>=1&&r<=ROW&&c>=1&&c<=COL)
			{
				if (map[r][c] >= 19 && map[r][c] <= 28)
				{
					if (map[r][c] != 20)//因为0周围不可能有雷
					{
						map[r][c] -= 20;
						count++;
					}
					else
					{
						OpenZero(r,c);
					}
				}
			}
		}
	}
}
int PlayGame()
{
	MOUSEMSG msg = { 0 };
	int r;
	int c;
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			r = msg.x / SIZE + 1;
			c = msg.y / SIZE + 1;
			if (map[r][c] >= 19 && map[r][c] <= 28)
			{
				if (map[r][c] == 20)
				{
					OpenZero(r,c);
				}
				else
				{
					map[r][c] -= 20;
					count++;
				}
			}
			return map[r][c];
			break;
		case WM_RBUTTONDOWN:
			r = msg.x / SIZE + 1;
			c = msg.y / SIZE + 1;
			if (map[r][c] >= 19 && map[r][c] <= 28)
			{
				map[r][c] += 20;
			}
			else if (map[r][c] >= 30)
			{
				map[r][c] -= 20;
			}
			return map[r][c];
			break;
		}
	}
}
int main()
{
	HWND hwnd=initgraph(ROW * SIZE, (COL+1) * SIZE,SHOWCONSOLE);
		loadimage(&img[0], L"0.jpg", SIZE, SIZE);
		loadimage(&img[1], L"1.jpg", SIZE, SIZE);
		loadimage(&img[2], L"2.jpg", SIZE, SIZE);
		loadimage(&img[3], L"3.jpg", SIZE, SIZE);
		loadimage(&img[4], L"4.jpg", SIZE, SIZE);
		loadimage(&img[5], L"5.jpg", SIZE, SIZE);
		loadimage(&img[6], L"6.jpg", SIZE, SIZE);
		loadimage(&img[7], L"7.jpg", SIZE, SIZE);
		loadimage(&img[8], L"8.jpg", SIZE, SIZE);
		loadimage(&img[9], L"9.jpg", SIZE, SIZE);//雷
		loadimage(&img[10], L"10.jpg", SIZE, SIZE);//空白
		loadimage(&img[11], L"11.jpg", SIZE, SIZE);
	GameInit();
	while (1)
	{
		Gamedraw();
		if (PlayGame()==-1)
		{
			Gamedraw();
			MessageBox(hwnd, L"你失败了!!", L"", MB_OK);
			break;
		}
		if (ROW * COL - NUM == count)
		{
			Gamedraw();
			MessageBox(hwnd, L"恭喜你赢了", L"", MB_OK);
			break;
		}
	}
	closegraph();
	return 0;
}