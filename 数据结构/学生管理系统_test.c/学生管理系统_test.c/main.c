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
		printf("��������Ҫѡ������֣�");
		scanf("%d", &select);

		switch (select)
		{
		case 1:  //�������ѧ����Ϣ
			printAllStudent(&sl);
			break;
		case 2:  //��ѧ�Ų�ѯѧ����Ϣ
			findStudent_Num(&sl);
			break;
		case 3:  //�޸�ѧ����Ϣ
			xiugai_Num(&sl);
			break;
		case 4:  //���һ��ѧ����Ϣ
			addStudent(&sl);
			break;
		case 5:  //ɾ��һ��ѧ����Ϣ
			deleteStudent(&sl);
			break;
		case 0:
			exit(0);
		default:
			printf("�����������������\n");
			break;
		}
		system("pause");
	}

	return 0;
}