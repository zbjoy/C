#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXSIZE 5
#define NUMMAX 13
#define NAMEMAX 8
#define CLASSNAMEMAX 15


typedef struct student
{
	char num[NUMMAX];//ѧ��
	char name[NAMEMAX];//����
	char classname[CLASSNAMEMAX];//�༶����
	int score;//�ɼ�
}datatype;

typedef struct StudentList
{
	datatype* data;
	int len;
	int capacity;
}SeqList;




void menu();

void initSeqList(SeqList* list);

void printAllStudent(SeqList* list);

void findStudent_Num(SeqList* list);

void xiugai_Num(SeqList* list);

void addStudent(SeqList* list);

void deleteStudent(SeqList* list);