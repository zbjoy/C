#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100  //���е���󳤶�
typedef char datatype;

int count = 0;
typedef struct
{
    //static int count;
    datatype name[20];  //����
    char sex;  //�Ա�ע�⣺��F��һ���ʾΪŮ�ԣ���M����ʾΪ���ԡ�
}Dancer;   //��������Ϣ

typedef struct    //��˳��洢�ṹ�����Ԫ��
{
    Dancer* e;  //�����е�����Ԫ������Ϊ�ṹ��Dancer
    int front;	   //ͷָ��
    int rear; //βָ��,�����в���,��ָ�����βԪ�ص���һ��λ��
}SeQueue;

Dancer* InitDancer()
{
    Dancer* d = (Dancer*)malloc(MAXSIZE * sizeof(Dancer));
}

SeQueue* InitQueue()
{
    SeQueue* q = (SeQueue*)malloc(sizeof(SeQueue));
    q->e = InitDancer();
    q->front = 0;
    q->rear = 0;
}

int Empty(SeQueue* q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int Enter(SeQueue* q, Dancer* d)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        return 0;
    }

    q->e[q->rear] = *d;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

int Pop(SeQueue* q, Dancer* d)
{
    if (Empty(q))
    {
        return 0;
    }
    *d = q->e[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

//SeQueue* q = InitQueue();

//SeQueue* q = (SeQueue*)malloc(sizeof(SeQueue));
//q->e = InitDancer();
//q->front = 0;
//q->rear = 0;

void dance(Dancer str_d[], SeQueue* qF, SeQueue* qM, int n)//nΪ�����������
{
    Dancer tempF;
    Dancer tempM;
    int i = 0;
    while (n--)
    {
        if (str_d[i].sex == 'F')
        {
            Enter(qF, &str_d[i++]);
        }
        else
        {
            Enter(qM, &str_d[i++]);
        }
    }

    while (!Empty(qF) && !Empty(qM))
    {
        Pop(qF, &tempF);
        Pop(qM, &tempM);
        printf("%s��%s��Ϊ�����\n", tempF.name, tempM.name);
    }
}

int main()
{
    SeQueue* qF = InitQueue();
    SeQueue* qM = InitQueue();
    Dancer d[15] = { {"1��",'F'},{"2��",'M'},{"3��",'F'}//10���պÿ����𣿣���
        ,{"4��",'F'},{"5��",'M'},{"6��",'F'}
        ,{"7��",'M'},{"8��",'F'},{"9��",'F'}
        ,{"10��",'M'} };
    dance(d, qF, qM, 10);
    Dancer d1[5] = { {"11��",'F'},{"12��",'M'},{"13��",'F'}};
    dance(d1, qF, qM, 3);
    return 0;
}
