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
		cout << "��������Ҫѡ��Ĺ��ܣ�";
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
			cout << "�����������������\n";
			break;
		}
		system("pause");
	} while (input);
}