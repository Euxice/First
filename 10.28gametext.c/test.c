#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("1.play\n");
	printf("0.exit\n");

}
void game()
{//��Ϣ�洢����������һ�������룬�ڶ����������
	char mine[ROWS][COLS] = { 0 };//����
	char show[ROWS][COLS] = { 0 };//����
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);//���������
	DisplayBoard(mine, ROW, COL);//��ʾ�趨��ֵ,����
	FindMine(mine, show, ROW, COL);//��ʼɨ��


}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("ѡ;>");
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
				printf("û�����ѡ��\n");
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