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
        printf("请输入你的选择:");
        scanf("%d", &select);

        switch (select)
        {
        case 1://输出所有学生信息
            print(&sl);
            break;
        case 2://按学号或姓名查询学生信息
            findStudent(&sl);
            break;
        case 3://修改学生信息
            modifyStudent(&sl);
            break;
        case 4://添加一个学生信息
            addStudent(&sl);
            break;
        case 5://删除一个学生信息
            deleteStudent(&sl);
            break;
        case 0://退出系统
            break;
        default:
            printf("输入有误，请重新输入\n");
            break;
        }
        system("pause");
    }


    printf("欢迎下次使用\n");
    return 0;
}