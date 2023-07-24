#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
void game()
{
	char board[ROW][COL] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
	biaoge(board, ROW, COL);
	while (1)
	{
		int ret = 0;
		peoplegame(board, ROW, COL);
		ret=isitwin_people(board,ROW,COL);
		if (ret == 1)
		{
			break;
		}
		computergame(board, ROW, COL);
		ret=isitwin_computer(board, ROW, COL);
		if (ret == 1)
		{
			break;
		}

	}
}