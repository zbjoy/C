#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef char DataType;

typedef struct
{
    DataType data[MAXSIZE];
    int top;
}SeqStack;

SeqStack* InitStack()  //��ʼ��ջs����Ϊ��ջ
{
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int StackEmpty(SeqStack* s)
{
    //�ж�s�Ƿ�Ϊ��ջ����Ϊ��ջ������1�����򷵻�0
    return  s->top == -1;
}

int  Push(SeqStack* s, DataType x)
{
    if (s->top == MAXSIZE - 1) //ջ��
    {
        printf("ջ����!\n");
        return 0;       //��ջʧ�ܷ���0
    }
    s->top++;        //ջ��ָ������1
    s->data[s->top] = x;  //����Ԫ�ظ�ֵ��ջ���ռ�
    return 1;            //��ջ�ɹ�����1
}

int Pop(SeqStack* s, DataType* px)
{
    if (StackEmpty(s))
    {
        printf("ջ��!\n");
        return 0;         //��ջʧ�ܷ���0
    }
    *px = s->data[s->top];  // ��ջ��Ԫ�ظ�ֵ��pxָ��ı���
    s->top--;                // ջ��ָ���1
    return  1;           //��ջ�ɹ�����1
}

int GetTop(SeqStack* s, DataType* px)
{
    if (StackEmpty(s))
    {
        //printf("ջ��!\n");
        return 0;         //��ȡջ��Ԫ��ʧ�ܷ���0
    }
    *px = s->data[s->top];  // ��ջ��Ԫ�ظ�ֵ��pxָ��ı���
    return  1;           //��ջ��Ԫ�سɹ�����1
}

int JudgeSerial(char str[], int n)
{//������Ϊn���ַ�����str��Ӧ������ȷ�ĳ�ջ���У�����1�����򷵻�0
    SeqStack* s;
    s = InitStack();
    char temp[10] = "ABCDEF";
    char t;
    //int count = 1;
    int count = 0;
    int i = 0;
    int j = 0;
    //Push(s, 'A');
    //printf("A��ջ\n");
    //for (i = 0; i < n; i++)
    //{
    //    GetTop(s, &t);
    //    if (str[i] != t)
    //    {
    //        Push(s, temp[count]);
    //        printf("%c��ջ\n", temp[count++]);
    //    }
    //    else
    //    {
    //        //if (StackEmpty(s))
    //        //{
    //        //    return 0;
    //        //}
    //        Push(s, str[i]);
    //        printf("%c��ջ\n", str[i]);
    //        Pop(s, &t);
    //        printf("%c��ջ\n", t);
    //    }
    //}
    for (i = 0; i < n; i++)
    {
        GetTop(s, &t);
        while (str[i] != t)
        {
            Push(s, temp[count]);
            printf("%c��ջ\n", temp[count++]);
            GetTop(s, &t);
            //if (str[i] == temp[count])
            //{
            //    Pop(s, &t);
            //    printf("%c��ջ\n", t);
            //    break;
            //}
        }
        //Push(s, temp[count]);
        //printf("%c��ջ\n", temp[count]);
        Pop(s, &t);
        printf("%c��ջ\n", t);
    }
    if (!StackEmpty(s))
    {
        return 0;
    }
    return 1;
}

int main()
{
    char str[MAXSIZE];
    int n = 5;
    //������жϵ��ַ�����
    scanf("%s", str);
    if (JudgeSerial(str, n))
        printf("%s��һ����ȷ�ĳ�ջ����\n", str);
    else
        printf("%s����һ����ȷ�ĳ�ջ����\n", str);
    return 0;
}
