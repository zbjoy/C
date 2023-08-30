#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SeqList.h"


int main()
{
	int select = 1;

	SeqList sl;
	initSeqList(&sl);
	while (select)
	{
		system("cls");
		menu();
		printf("请输入您要选择的数字：");
		scanf("%d", &select);

		switch (select)
		{
		case 1:  //输出所有学生信息
			printAllStudent(&sl);
			break;
		case 2:  //按学号查询学生信息
			findStudent_Num(&sl);
			break;
		case 3:  //修改学生信息
			xiugai_Num(&sl);
			break;
		case 4:  //添加一个学生信息
			addStudent(&sl);
			break;
		case 5:  //删除一个学生信息
			deleteStudent(&sl);
			break;
		case 0:
			exit(0);
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		system("pause");
	}

	return 0;
}