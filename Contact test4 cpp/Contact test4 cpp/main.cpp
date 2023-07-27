#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


int main()
{
	int input = 0;
	Contact con;
	ContactInIt(&con);
	do
	{
		system("cls");
		menu();
		cout << "请输入你要选择的功能：";
		cin >> input;
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			FindContact(&con);
			break;
		case 3:
			SaveContact(&con);
			break;
		case 4:
			DelContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 0:
			SaveContact(&con);
			break;
		default:
			cout << "输入错误，请重新输入\n";
			break;
		}
		system("pause");
	} while (input);
}