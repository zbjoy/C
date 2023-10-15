//#include <windows.h>
//#include <mmsystem.h>
//
//#pragma comment(linker,"/subsystem:/"windows/" /entry:/"mainCRTStartup/"")

#include <iostream>
#include <graphics.h>
#include <conio.h>

#include "MainScene.h"
#include "PlayScene.h"

#ifndef MAINSCENESIZE
#define MAINSCENESIZE

#define MAINSCENE_HEIGHT 600
#define MAINSCENE_WEIGHT 400

#define MAINBUTTON_LEFT_PLAY 155
#define MAINBUTTON_TOP_PLAY 360
#define MAINBUTTON_RIGHT_PLAY 240
#define MAINBUTTON_BOTTOM_PLAY 400

#define MAINBUTTON_LEFT_EXIT 155
#define MAINBUTTON_TOP_EXIT 480
#define MAINBUTTON_RIGHT_EXIT 240
#define MAINBUTTON_BOTTOM_EXIT 520

#endif



#ifndef PLAYSCENE_SIZE
#define PLAYSCENE_SIZE

#define INTERVAL 50 //���
#define CHESS_GRID_SIZE 70  //���ӿ��
#define ROW 10
#define COL 9
#define SIZE 60
#define BUTTON_SIZE 20
#define PLAYSCENEBUTTON_LEFT_EXIT 650
#define PLAYSCENEBUTTON_RIGHT_EXIT 750
#define PLAYSCENEBUTTON_TOP_EXIT 300
#define PLAYSCENEBUTTON_BOTTOM_EXIT 360

#endif

extern bool Red;
bool Red = true;
int ChessMap[ROW][COL];
/*

0 ��

�췽�� 1 ��    2 ��		3 ��		4 ��		5 ��		6 ʿ		7 ˧

�ڷ��� 8 ��	   9 ��		10 ��		11 ��		12 ��		13 ʿ		14 ��

*/

void InitChessMap(int ChessMap[][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (((i == 0 || i == ROW - 1) && j == 0) || ((i == 0 || i == ROW - 1) && j == COL - 1))
			{
				if (i == 0)
				{
					ChessMap[i][j] = 3;
				}
				else
				{
					ChessMap[i][j] = 10;
				}
			}
			else if (((i == 0 || i == ROW - 1) && j == 1) || ((i == 0 || i == ROW - 1) && j == COL - 2))
			{
				if (i == 0)
				{
					ChessMap[i][j] = 4;
				}
				else
				{
					ChessMap[i][j] = 11;
				}
			
			}
			else if (((i == 0 || i == ROW - 1) && j == 2) || ((i == 0 || i == ROW - 1) && j == COL - 3))
			{
				if (i == 0)
				{
					ChessMap[i][j] = 5;
				}
				else
				{
					ChessMap[i][j] = 12;
				}
			}
			else if (((i == 0 || i == ROW - 1) && j == 3) || ((i == 0 || i == ROW - 1) && j == COL - 4))
			{
				if (i == 0)
				{
					ChessMap[i][j] = 6;
				}
				else
				{
					ChessMap[i][j] = 13;
				}
			}
			else if (((i == 0 || i == ROW - 1) && j == 4))
			{
				if (i == 0)
				{
					ChessMap[i][j] = 7;
				}
				else
				{
					ChessMap[i][j] = 14;
				}
			}
			else if ((i == 3 || i == ROW - 4) && (j == 0 || j == 2 || j == 4 || j == 6 || j == 8 || j == 10))
			{
				if (i == 3)
				{
					ChessMap[i][j] = 1;
				}
				else
				{
					ChessMap[i][j] = 8;
				}
			}
			else if ((i == 2 || i == ROW - 3) && (j == 1 || j == COL - 2))
			{
				if (i == 2)
				{
					ChessMap[i][j] = 2;
				}
				else
				{
					ChessMap[i][j] = 9;
				}
			}
			else
			{
				ChessMap[i][j] = 0;
			}

		}
	}
}

//void printMap(int Map[][COL])
//{
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			std::cout << Map[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}

int main()
{
	InitChessMap(ChessMap);
	MOUSEMSG msg;
	IMAGE MainImage;
	int Select = -1;
	do
	{
		initgraph(MAINSCENE_WEIGHT, MAINSCENE_HEIGHT);
		//InitMainScene(MainImage);
		loadimage(&MainImage, _T("������.png"), MAINSCENE_WEIGHT, MAINSCENE_HEIGHT);
		putimage(0, 0, &MainImage);

		//fillrectangle(155, 480, 240, 520);
		//fillrectangle(155, 420, 240, 460);
		//fillrectangle(155, 360, 240, 400);

		msg = GetMouseMsg();
		Select = MainMouseContral(msg);

		if (Select == 1) //��Ϸ����
		{
			closegraph();
			int Judge = 1;
			while (Judge)
			{
				initgraph(800, 800);
				GameDraw();
				setlinecolor(BLACK);
				CheckChess(ChessMap);
				int ret = ChessWin(ChessMap);
				if (ret == 1) // ��Ӯ
				{
					settextstyle(60, 0, _T("����"));
					TCHAR text[30] = _T("�췽ʤ��");
					outtextxy(300, 300, text);
				}
				else if (ret == 2) //��Ӯ
				{
					settextstyle(60, 0, _T("����"));
					TCHAR text[30] = _T("�ڷ�ʤ��");
					outtextxy(300, 300, text);
				}
				
				if (Red)
				{
					setlinecolor(RED);
					TCHAR RedPlay[30] = _T("�췽����");
					settextcolor(BLACK);
					settextstyle(35, 0, _T("����"));
					outtextxy(630, 200, RedPlay);
				}
				else
				{
					setlinecolor(BLACK);
					TCHAR BlackPlay[30] = _T("�ڷ�����");
					settextcolor(BLACK);
					settextstyle(35, 0, _T("����"));
					outtextxy(630, 500, BlackPlay);
				}
				//msg = GetMouseMsg();
				Judge = PlayScene(msg, ChessMap);
			}
		}

	} while (Select);
	return 0;
}