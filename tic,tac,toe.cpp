#if 0
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void Menu()
{
	printf("****************\n");
	printf("**1开始**0结束**\n");
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
	printf("玩家开始下棋：\n");
	printf("请输入坐标：\n");
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
				printf("请重新输入：\n");
			}
			
		}
		else
		{
			printf("请在规定范围内重新输入：\n");
		}
	}
}
void ComputerBegin(char(*board)[COL], int row, int col)
{
	printf("计算机开始下棋：\n");
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
	//平局所有的棋子全部下满
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
	//三横行 三竖行 左右斜,分别可能的返回值是“*”“#”
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
	//还有最后一种平局的情况draw
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
	//初始化九宫格为“ ”，并设置格式
	Init_Game(board,ROW,COL);
	Print_Game(board, ROW, COL);
	while (1)
	{
		//玩家开始走
		PlayerBegin(board, ROW, COL);
		Print_Game(board, ROW, COL);
		rat = IS_Win(board, ROW, COL);
		if (rat != 'C')
		{
			break;
		}
		//电脑开始走
		ComputerBegin(board, ROW, COL);
		Print_Game(board, ROW, COL);
		rat = IS_Win(board, ROW, COL);
		if (rat != 'C')
		{
			break;
		}
		//判断输赢情况：玩家赢“*”，电脑赢“#”，平局“Q”,继续“C”
		if (rat == '*')
		{
			printf("游戏玩家胜利！\n");
		}
		else if (rat == '#')
		{
			printf("计算机胜利！\n");
		}
		else
		{
			printf("平局！\n");
		}
	}
}
void Text()
{
	int input = 0;
	//请输入0或者1来判断游戏是否开始
	//需要调用目录来使玩家选择
	Menu();
	printf("请选择（1游戏开始0游戏结束）");
	scanf_s("%d", &input);
	do
	{
		//1游戏开始
		//0游戏结束
		//其他输入错误请重新
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入（0/1）:\n");
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
