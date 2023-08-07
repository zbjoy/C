#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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
void Calc(int(*pf)(int,int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请选择两个操作数：");
	scanf("%d%d", &x, &y);
	system("cls");
	ret = pf(x, y);
	printf("所得结果为%d\n", ret);
	system("pause");
	system("cls");
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出Calc\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}