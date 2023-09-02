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

void menu();//�˵�

void InItSeqList(SeqList* psl);//��ʼ��

void CheckCapacity(SeqList* psl);//��������Ƿ��㹻������realloc����ռ�

void saveStudent(SeqList* psl);//����ѧ����Ϣ��student.txt�ļ�

void LoadStudent(SeqList* psl);//��"student.txt"�ļ��н���Ϣ��ȡ����

void print(SeqList* psl);//��ӡ����ѧ����Ϣ

void findStudent(SeqList* psl);//��ѧ�Ż���������ѧ��

void modifyStudent(SeqList* psl);//�޸�ѧ����Ϣ

void addStudent(SeqList* psl);//���ѧ����Ϣ

void deleteStudent(SeqList* psl);//ɾ��ѧ����Ϣ