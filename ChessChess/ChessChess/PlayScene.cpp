#include "PlayScene.h"

extern bool Red;

void GameDraw()
{
	
	setbkcolor(RGB(252, 215, 162));
	cleardevice();
	setlinecolor(BLACK);  //������ɫ
	setlinestyle(PS_SOLID, 2); //������ʽ���߿�
	//����߿�
	setfillcolor(RGB(252, 215, 162));
	//������
	fillrectangle(INTERVAL - 5, INTERVAL - 5
		, CHESS_GRID_SIZE * (COL - 1) + INTERVAL + 5
		, CHESS_GRID_SIZE * (ROW - 1) + INTERVAL + 5);
	//������
	for (int i = 0; i < ROW; i++)
	{
		//������
		line(INTERVAL, i * CHESS_GRID_SIZE + INTERVAL
			, CHESS_GRID_SIZE * (COL - 1) + INTERVAL, i * CHESS_GRID_SIZE + INTERVAL);

		if (i < COL)
		{
			//������
			line(i * CHESS_GRID_SIZE + INTERVAL, INTERVAL
				, i * CHESS_GRID_SIZE + INTERVAL, CHESS_GRID_SIZE * (ROW - 1) + INTERVAL);
		}
	}

	//��ʾ����, ����
	fillrectangle(INTERVAL, (ROW / 2 - 1) * CHESS_GRID_SIZE + INTERVAL
		, INTERVAL + (COL - 1) * CHESS_GRID_SIZE, ROW / 2 * CHESS_GRID_SIZE + INTERVAL);

	//��ʾ����
	settextcolor(BLACK);
	settextstyle(50, 0, _T("����"));
	TCHAR river[30] = _T("����         ����");

	//�����־���
	int twidth = textwidth(river);
	int theight = textheight(river);
	twidth = ((COL - 1) * CHESS_GRID_SIZE - twidth) / 2;
	theight = (CHESS_GRID_SIZE - theight) / 2;
	outtextxy(INTERVAL + twidth, (ROW / 2 - 1) * CHESS_GRID_SIZE + theight + INTERVAL, river);

	//�˳�ͼ��
	/*setbkcolor(RED);
	setfillcolor(RED);
	fillrectangle(650, 300, 750, 360);
	settextcolor(WHITE);
	settextstyle(50, 0, _T("����"));
	TCHAR Exit[20] = _T("�˳�");
	outtextxy(650, 310, Exit);*/
	IMAGE Exit;
	loadimage(&Exit, _T("�˳�.png"), 100, 60);
	putimage(PLAYSCENEBUTTON_LEFT_EXIT, PLAYSCENEBUTTON_TOP_EXIT, &Exit);


	//������

	setlinecolor(RED);
	//�Ϸ�
	line(INTERVAL + (COL / 2 - 1) * CHESS_GRID_SIZE, INTERVAL
		, INTERVAL + (COL / 2 + 1) * CHESS_GRID_SIZE, INTERVAL + 2 * CHESS_GRID_SIZE);
	line(INTERVAL + (COL / 2 - 1) * CHESS_GRID_SIZE, INTERVAL + 2 * CHESS_GRID_SIZE
		, INTERVAL + (COL / 2 + 1) * CHESS_GRID_SIZE, INTERVAL);
	//�·�
	line(INTERVAL + (COL / 2 - 1) * CHESS_GRID_SIZE, INTERVAL + (ROW - 3) * CHESS_GRID_SIZE
		, INTERVAL + (COL / 2 + 1) * CHESS_GRID_SIZE, INTERVAL + (ROW - 1) * CHESS_GRID_SIZE);
	line(INTERVAL + (COL / 2 - 1) * CHESS_GRID_SIZE, INTERVAL + (ROW - 1) * CHESS_GRID_SIZE
		, INTERVAL + (COL / 2 + 1) * CHESS_GRID_SIZE, INTERVAL + (ROW - 3) * CHESS_GRID_SIZE);


	
}

int PlayScene(MOUSEMSG& msg, int ChessMap[][COL])
{
	int Select = PlayMouseContral(msg, ChessMap);

	if (Select == 0)
	{
		return 0;
	}

	return 1;
}

int PlayMouseContral(MOUSEMSG& msg, int ChessMap[][COL])
{
	while (MouseHit)
	{
		msg = GetMouseMsg();

		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= PLAYSCENEBUTTON_LEFT_EXIT && msg.x <= PLAYSCENEBUTTON_RIGHT_EXIT && msg.y >= PLAYSCENEBUTTON_TOP_EXIT && msg.y <= PLAYSCENEBUTTON_BOTTOM_EXIT)
			{
				return 0;
			}
			else
			{
				for (int i = 0; i < ROW; i++)
				{
					for (int j = 0; j < COL; j++)
					{
						if (msg.x >= INTERVAL - BUTTON_SIZE + j * CHESS_GRID_SIZE && msg.x <= INTERVAL + BUTTON_SIZE + j * CHESS_GRID_SIZE
							&& msg.y >= INTERVAL - BUTTON_SIZE + i * CHESS_GRID_SIZE && msg.y <= INTERVAL + BUTTON_SIZE + i * CHESS_GRID_SIZE)
						{
							//static bool PlayPeople = true;
							if (Red && ChessMap[i][j] <= 7 && ChessMap[i][j] >= 1)
							{
								ChessMove(msg, ChessMap, i, j);
							}
							else if(!Red && ChessMap[i][j] >= 8 && ChessMap[i][j] <= 14)
							{
								ChessMove(msg, ChessMap, i, j);
							}
	
							return 1;
						}
					}
				}
				return 1;
			}
		default:
			break;
		}
	}
}

void CheckChess(int ChessMap[][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (ChessMap[i][j] == 0) {}
			else if (ChessMap[i][j] == 1)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 2)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 3)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 4)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 5)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 6)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("ʿ");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//ʿ
			}
			else if (ChessMap[i][j] == 7)
			{
				settextcolor(RED);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("˧");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//˧				
			}
			else if (ChessMap[i][j] == 8)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 9)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 10)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 11)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 12)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
			else if (ChessMap[i][j] == 13)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("ʿ");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//ʿ
			}
			else if (ChessMap[i][j] == 14)
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("����"));
				circle(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE, 25);
				TCHAR Chess_Name[10] = _T("��");
				outtextxy(INTERVAL + j * CHESS_GRID_SIZE - 15, INTERVAL + i * CHESS_GRID_SIZE - 15, Chess_Name);
				//��
			}
		}
	}
}

void ChessMove(MOUSEMSG& msg, int ChessMap[][COL], int i, int j)
{
	if (ChessMap[i][j] == 0)
	{
		return;
	}


	while (MouseHit)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			for (int y = 0; y < ROW; y++)
			{
				for (int x = 0; x < COL; x++)
				{
					if (msg.x >= INTERVAL - BUTTON_SIZE + x * CHESS_GRID_SIZE
						&& msg.x <= INTERVAL + BUTTON_SIZE + x * CHESS_GRID_SIZE
						&& msg.y <= INTERVAL + BUTTON_SIZE + y * CHESS_GRID_SIZE
						&& msg.y >= INTERVAL - BUTTON_SIZE + y * CHESS_GRID_SIZE)
					{
						bool Judge = false;
						if (ChessMap[i][j] == 1) //���
						{							
							Judge = RedBin_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 2) //����
						{
							Judge = RedPao_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 3) //�쳵
						{
							Judge = RedChe_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 4) //����
						{
							Judge = RedMa_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 5) //����
						{
							Judge = RedXiang_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 6) //��ʿ
						{
							Judge = RedShi_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 7) //˧
						{
							Judge = Shuai_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 8) //����
						{
							Judge = BlackBin_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 9) //����
						{
							Judge = BlackPao_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 10) //�ڳ�
						{
							Judge = BlackChe_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 11) //����
						{
							Judge = BlackMa_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 12) //����
						{
							Judge = BlackXiang_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 13) //��ʿ
						{
							Judge = BlackShi_Move(x, y, ChessMap, i, j);
						}
						else if (ChessMap[i][j] == 14) //��
						{
							Judge = Jiang_Move(x, y, ChessMap, i, j);
						}

						if (Judge)
						{
							ChessMap[y][x] = ChessMap[i][j]; //�տ�ʼд��[x][y]��
							ChessMap[i][j] = 0;
							Red = !Red;
						}
						return;
					}
				}
			}

		}
	}


}

int ChessWin(int ChessMap[][COL])
{
	bool Shuai = false;
	bool Jiang = false;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (ChessMap[i][j] == 7)
			{
				Shuai = true;
			}
			if (ChessMap[i][j] == 14)
			{
				Jiang = true;
			}
		}
	}

	if (!Shuai)
	{
		return 2;
	}
	else if (!Jiang)
	{
		return 1;
	}
	return 0;
}