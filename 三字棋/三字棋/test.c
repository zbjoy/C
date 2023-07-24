#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void biaoge(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0;j < col;j++)
		{
			if (j < col - 1)
			{
				printf(" %c ", board[i][j]);
				printf("|");
			}
			else
				printf(" %c \n", board[i][j]);
		}
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
				{
					printf("___|");
				}
				else
					printf("___\n");
			}
		}
		
	}
}
void peoplegame(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("���������꣺");
		scanf("%d%d", &i, &j);
		if (board[i-1][j-1] == ' ')
		{
			board[i-1][j-1] = '*';
			biaoge(board, ROW, COL);
			break;
		}
		else
			printf("�������ӻ��������ڣ�����������\n");
	}
}
int isitpinju(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	printf("ƽ��\n");
	return 1;
}
int isitwin_people(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			printf("��ϲ��Ӯ��\n");
			bingdu_zhangjiahao();
			return 1;
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			printf("��ϲ��Ӯ��\n");
			bingdu_zhangjiahao();
			return 1;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		printf("��ϲ��Ӯ��\n");
		bingdu_zhangjiahao();
		return 1;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		printf("��ϲ��Ӯ��\n");
		bingdu_zhangjiahao();
		return 1;
	}
	else
	{
		int q = 0;
		q=isitpinju(board,ROW,COL);
		if (q == 1)
			return 1;
		else
			return 0;
	}
}
int isitwin_computer(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			printf("��ϲ�㱻���˻�����ˣ�����Цһ�ᣬ������\n");
			return 1;
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			printf("��ϲ�㱻���˻�����ˣ�����Цһ�ᣬ������\n");
			return 1;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		printf("��ϲ�㱻���˻�����ˣ�����Цһ�ᣬ������\n");
		return 1;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		printf("��ϲ�㱻���˻�����ˣ�����Цһ�ᣬ������\n");
		return 1;
	}
	else
	{
		int q = 0;
		q = isitpinju(board, ROW, COL);
		if (q == 1)
			return 1;
		else
			return 0;
	}
}
void computergame(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("�밴�����ʹ�������壺\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col; 
		if (board[i][j] == ' ')
		{
			system("pause");
			board[i][j] = '#';
			system("cls");
			biaoge(board, ROW, COL);
			break;
		}
	}
}
void menu()
{
	printf("*******************************\n");
	printf("******* 1.play   0.exit *******\n");
	printf("*******************************\n");
}
int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//�˵�����
		scanf("%d", &n);
		if (n == 1)
		{
			printf("��Ϸ��ʼ\n");
			game();
			printf("�Ƿ�����һ��");
		}
		else if (n == 0)
		{
			printf("�˳���Ϸ\n");
			break;
		}
		else
			printf("����������������룡");
	} while (1);
	return 0;
}