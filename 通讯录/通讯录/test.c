#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*************************************\n");
	printf("******1.add           2.del    ******\n");
	printf("******3.search        4.modify ******\n");
	printf("******5.show          6.sort   ******\n");
	printf("******7.capacity      8.save   ******\n");
	printf("******        0.exit           ******\n");
	printf("*************************************\n");
}
int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do
	{
		system("cls");
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact_Byage(&con);
			break;
		case 7:
			QuestionCapacity(&con);
			break;
		case 8:
			SaveContact(&con);
			break;
		case 0:
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出contact\n");
			break;
		default://输入数字非switch中的可以，但字符和汉字会导致Bug，为什么？
			printf("输入错误，请重新输入\n");
			break;
		}
		system("pause");
	} while (input);
	return 0;
}