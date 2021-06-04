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
	printf("��ҿ�ʼ���壺>\n");
	printf("��������Ҫ�µ����꣺\n");
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
				printf("���������룺\n");
			}
		}
		else
		{
			printf("���ں���Χ�����루3��3����\n");
		}
	}
}
void ComputerBegin(char(*board)[COL], int row, int col)
{
	printf("���Կ�ʼ���壺>\n");
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
//����1��ʾ�������ˣ�����0��ʾ����û��
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
	//����������������б��,һ�η��ض�Ӧ�Ľ�����־�����˳�ѭ��
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
	//��������һ��ߵ���Ӯ��������ֱ����������ǡ�*�����ߡ�#����
	//֮����ܵ������ƽ�֣��������˲��Ҷ�û��Ӯ
	if (ISFull(board,row,col) == 1)
	{
		return 'Q';
	}
	return 'C';
}
#endif