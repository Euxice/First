#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//��ʼ������
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int rows, int cols)
{
	int i, j;//��ӡ�к�
	for (i = 0; i <= COL; i++)
	{
		printf("%d ", i);
	}
	printf("\n");//����
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("��������ɨ�ף�>");
		scanf_s("%d %d", &x, &y);
		getchar();
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("��\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//�����ף��ܱ��㷨
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				if (count == 0)
				{
					int i, j;
					for (i = -1; i <= 1; i++)
					{
						for (j = -1; j <= 1; j++)
						{
							if (i == 0 && j == 0)
								continue;
							Reveal(mine, show, x + i, y + j);
						}
					}
				}
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("����\n");
			
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("���Եģ���ţ�ƣ�\n");
		DisplayBoard(mine, row, col);
	}
}
//չ��������Ҫ�ݹ�
//1���겻�����Ҹ�������ΧҲ���ף���ݹ�
void Reveal(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	
	
	if(x<0 || x>=ROW || y <0 || y>=COL)
		return;
	if (show[x][y] == '0')
		return;
	int mine_count = get_mine_count(mine, x, y);
	show[x][y] = mine_count + '0';
	if (mine_count == 0)
	{
		int i, j;
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if(i == 0 && j == 0)
					continue;
				Reveal(mine, show, x + i, y + j);
			}
		}
	}

}