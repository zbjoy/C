#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100  //队列的最大长度
typedef char datatype;

int count = 0;
typedef struct
{
    //static int count;
    datatype name[20];  //姓名
    char sex;  //性别。注意：‘F’一般表示为女性，‘M’表示为男性。
}Dancer;   //跳舞者信息

typedef struct    //用顺序存储结构存队列元素
{
    Dancer* e;  //队列中的数据元素类型为结构体Dancer
    int front;	   //头指针
    int rear; //尾指针,若队列不空,则指向队列尾元素的下一个位置
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

void dance(Dancer str_d[], SeQueue* qF, SeQueue* qM, int n)//n为输入的总人数
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
        printf("%s与%s成为了舞伴\n", tempF.name, tempM.name);
    }
}

int main()
{
    SeQueue* qF = InitQueue();
    SeQueue* qM = InitQueue();
    Dancer d[15] = { {"1号",'F'},{"2号",'M'},{"3号",'F'}//10个刚好可以吗？？？
        ,{"4号",'F'},{"5号",'M'},{"6号",'F'}
        ,{"7号",'M'},{"8号",'F'},{"9号",'F'}
        ,{"10号",'M'} };
    dance(d, qF, qM, 10);
    Dancer d1[5] = { {"11号",'F'},{"12号",'M'},{"13号",'F'}};
    dance(d1, qF, qM, 3);
    return 0;
}
