#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include "list.h"

int main()
{
    SeqList sl;

    InItSeqList(&sl);

    //printf("%d",sl.size);

    int select = 1;

    while (select)
    {
        system("cls");
        menu();
        printf("���������ѡ��:");
        scanf("%d", &select);

        switch (select)
        {
        case 1://�������ѧ����Ϣ
            print(&sl);
            break;
        case 2://��ѧ�Ż�������ѯѧ����Ϣ
            findStudent(&sl);
            break;
        case 3://�޸�ѧ����Ϣ
            modifyStudent(&sl);
            break;
        case 4://���һ��ѧ����Ϣ
            addStudent(&sl);
            break;
        case 5://ɾ��һ��ѧ����Ϣ
            deleteStudent(&sl);
            break;
        case 0://�˳�ϵͳ
            break;
        default:
            printf("������������������\n");
            break;
        }
        system("pause");
    }


    printf("��ӭ�´�ʹ��\n");
    return 0;
}