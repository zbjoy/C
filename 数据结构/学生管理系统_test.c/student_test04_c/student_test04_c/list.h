#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NUMMAX 11
#define NAMEMAX 10
#define SEXMAX 3
#define CLASSMAX 10
#define TELEMAX 12

#define STARTCAP 5

typedef struct student
{
    char m_Num[NUMMAX];
    char m_Name[NAMEMAX];
    char m_Sex[SEXMAX];
    char m_ClassName[CLASSMAX];
    char m_Tele[TELEMAX];
    int m_Score;
}student;

typedef struct SeqList
{
    student* data;
    int size;
    int capacity;
}SeqList;

void menu();//菜单

void InItSeqList(SeqList* psl);//初始化

void CheckCapacity(SeqList* psl);//检查容量是否足够，不够realloc更多空间

void saveStudent(SeqList* psl);//保存学生信息到student.txt文件

void LoadStudent(SeqList* psl);//从"student.txt"文件中将信息读取处理

void print(SeqList* psl);//打印所有学生信息

void findStudent(SeqList* psl);//按学号或姓名查找学生

void modifyStudent(SeqList* psl);//修改学生信息

void addStudent(SeqList* psl);//添加学生信息

void deleteStudent(SeqList* psl);//删除学生信息