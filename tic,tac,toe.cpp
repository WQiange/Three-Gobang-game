#if 0
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void Menu()
{
	printf("****************\n");
	printf("**1��ʼ**0����**\n");
	printf("****************\n");
}
void Init_Game(char(*board)[COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Print_Game(char(*board)[COL], int row, int col)
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
			for (int j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1)
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
	int x = 0;
	int y = 0;
	printf("��ҿ�ʼ���壺\n");
	printf("���������꣺\n");
	scanf_s("%d %d", &x, &y);//2 2
	while (1)
	{
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] ==' ')
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
			printf("���ڹ涨��Χ���������룺\n");
		}
	}
}
void ComputerBegin(char(*board)[COL], int row, int col)
{
	printf("�������ʼ���壺\n");
	int x = 0;
	int y = 0;
	
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}
int Draw(char(*board)[COL], int row, int col)
{
	//ƽ�����е�����ȫ������
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(board[i][j] != ' ')
			{
				return 1;
				break;
			}
		}
	}
	return 0;
}
char IS_Win(char(*board)[COL], int row, int col)
{
	//������ ������ ����б,�ֱ���ܵķ���ֵ�ǡ�*����#��
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�������һ��ƽ�ֵ����draw
	if (Draw(board, row, col) == 1)
	{
		return 'Q';
	}
	return 'C';
}
void Game()
{
	int rat = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ���Ź���Ϊ�� ���������ø�ʽ
	Init_Game(board,ROW,COL);
	Print_Game(board, ROW, COL);
	while (1)
	{
		//��ҿ�ʼ��
		PlayerBegin(board, ROW, COL);
		Print_Game(board, ROW, COL);
		rat = IS_Win(board, ROW, COL);
		if (rat != 'C')
		{
			break;
		}
		//���Կ�ʼ��
		ComputerBegin(board, ROW, COL);
		Print_Game(board, ROW, COL);
		rat = IS_Win(board, ROW, COL);
		if (rat != 'C')
		{
			break;
		}
		//�ж���Ӯ��������Ӯ��*��������Ӯ��#����ƽ�֡�Q��,������C��
		if (rat == '*')
		{
			printf("��Ϸ���ʤ����\n");
		}
		else if (rat == '#')
		{
			printf("�����ʤ����\n");
		}
		else
		{
			printf("ƽ�֣�\n");
		}
	}
}
void Text()
{
	int input = 0;
	//������0����1���ж���Ϸ�Ƿ�ʼ
	//��Ҫ����Ŀ¼��ʹ���ѡ��
	Menu();
	printf("��ѡ��1��Ϸ��ʼ0��Ϸ������");
	scanf_s("%d", &input);
	do
	{
		//1��Ϸ��ʼ
		//0��Ϸ����
		//�����������������
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("����������������루0/1��:\n");
			break;
		}
	} while (1);
}
int mian()
{
	Text();
	return 0;
}
#endif
