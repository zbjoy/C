#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

int main()
{
	int select = 0;
	Contact con;
	InItContact(&con);
	do
	{
		system("cls");
		menu();
		printf("请输入您的选择：");
		scanf("%d", &select);//scanf返回值是什么???
		switch (select)
		{
		case 1://add
			addContact(&con);
			break;
		case 2://del
			delContact(&con);
			break;
		case 3://search
			searchContact(&con);
			break;
		case 4://modify
			break;
		case 5://show
			showContact(&con);
			break;
		case 6://sort
			sortContact(&con);
			break;
		case 7://capacity
			capacity(&con);
			break;
		case 8://save
			save(&con);
			printf("已保存\n");
			break;
		case 0://exit
			printf("欢迎下次使用\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		system("pause");
	} while (select);
	return 0;
}