#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("1.play\n");
	printf("0.exit\n");

}
void game()
{//信息存储分两步，第一步是输入，第二步是输出。
	char mine[ROWS][COLS] = { 0 };//里盘
	char show[ROWS][COLS] = { 0 };//表盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);//随机放置雷
	DisplayBoard(mine, ROW, COL);//显示设定数值,里盘
	FindMine(mine, show, ROW, COL);//开始扫雷


}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("选;>");
		scanf_s("%d", &input);
		getchar();
		
		switch (input)
		{
		case 1:
				game();
				break;
		case 0:
                    printf("exit\n");
                    break;
        default:
				printf("没有这个选项\n");
				break;


		}
	}
	while (input);
}
int main()
{
	test();
	return 0;
}