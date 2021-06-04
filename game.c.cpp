#if 0
#include "game.h"
void InitBord(char board[ROW][COL], int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void PrintBord(char(*board)[COL], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);	
			if (j < col - 1)
			{
               printf("|");
			}	
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
			{
				printf("___");
				if (k < col - 1)
				{
					printf("|");
				}
			}
         printf("\n");
		}
	}
}
void PlayerBegin(char(*board)[COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家开始下棋：>\n");
	printf("请输入你要下的坐标：\n");
	scanf_s("%d %d", &x, &y);
	while (1)
	{
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("请重新输入：\n");
			}
		}
		else
		{
			printf("请在合理范围内输入（3，3）！\n");
		}
	}
}
void ComputerBegin(char(*board)[COL], int row, int col)
{
	printf("电脑开始下棋：>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] == '#';
			break;
		}
	}
}
//返回1表示棋盘满了，返回0表示棋盘没满
int ISFull(char(*board)[COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char IsWin(char(*board)[COL], int row, int col)
{
	//横三，竖三，左右斜三,一次返回对应的结束标志，并退出循环
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (int i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//上述是玩家或者电脑赢的情况，分别可能输出的是“*”或者“#”；
	//之后可能的情况是平局，棋盘满了并且都没有赢
	if (ISFull(board,row,col) == 1)
	{
		return 'Q';
	}
	return 'C';
}
#endif