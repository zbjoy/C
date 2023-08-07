#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("****************************\n");
	printf("*****   1.add  2.sub   *****\n");
	printf("*****   3.mul  4.div   *****\n");
	printf("*****     0.exit       *****\n");
	printf("****************************\n");
}
int main()
{
	int(*Arr[5])(int, int) = { 0,Add,Sub,Mul,Div };
	int input = 0;
	do
	{
		system("cls");
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			int x = 0;
			int y = 0;
			int ret = 0;
			printf("请选择两个操作数：");
			scanf("%d%d", &x, &y);
			system("cls");
			ret=Arr[input](x, y);
			printf("所得结果为:%d\n", ret);
			system("pause");
		}
		else if (input == 0)
		{
			printf("退出Calc");
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	

	return 0;
}