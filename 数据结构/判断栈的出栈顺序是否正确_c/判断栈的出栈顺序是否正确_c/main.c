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

SeqStack* InitStack()  //初始化栈s，置为空栈
{
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int StackEmpty(SeqStack* s)
{
    //判断s是否为空栈，若为空栈，返回1，否则返回0
    return  s->top == -1;
}

int  Push(SeqStack* s, DataType x)
{
    if (s->top == MAXSIZE - 1) //栈满
    {
        printf("栈已满!\n");
        return 0;       //入栈失败返回0
    }
    s->top++;        //栈顶指针增加1
    s->data[s->top] = x;  //将新元素赋值给栈顶空间
    return 1;            //入栈成功返回1
}

int Pop(SeqStack* s, DataType* px)
{
    if (StackEmpty(s))
    {
        printf("栈空!\n");
        return 0;         //出栈失败返回0
    }
    *px = s->data[s->top];  // 将栈顶元素赋值给px指向的变量
    s->top--;                // 栈顶指针减1
    return  1;           //出栈成功返回1
}

int GetTop(SeqStack* s, DataType* px)
{
    if (StackEmpty(s))
    {
        //printf("栈空!\n");
        return 0;         //读取栈顶元素失败返回0
    }
    *px = s->data[s->top];  // 将栈顶元素赋值给px指向的变量
    return  1;           //读栈顶元素成功返回1
}

int JudgeSerial(char str[], int n)
{//若长度为n的字符序列str对应的是正确的出栈序列，返回1；否则返回0
    SeqStack* s;
    s = InitStack();
    char temp[10] = "ABCDEF";
    char t;
    //int count = 1;
    int count = 0;
    int i = 0;
    int j = 0;
    //Push(s, 'A');
    //printf("A入栈\n");
    //for (i = 0; i < n; i++)
    //{
    //    GetTop(s, &t);
    //    if (str[i] != t)
    //    {
    //        Push(s, temp[count]);
    //        printf("%c入栈\n", temp[count++]);
    //    }
    //    else
    //    {
    //        //if (StackEmpty(s))
    //        //{
    //        //    return 0;
    //        //}
    //        Push(s, str[i]);
    //        printf("%c入栈\n", str[i]);
    //        Pop(s, &t);
    //        printf("%c出栈\n", t);
    //    }
    //}
    for (i = 0; i < n; i++)
    {
        GetTop(s, &t);
        while (str[i] != t)
        {
            Push(s, temp[count]);
            printf("%c入栈\n", temp[count++]);
            GetTop(s, &t);
            //if (str[i] == temp[count])
            //{
            //    Pop(s, &t);
            //    printf("%c出栈\n", t);
            //    break;
            //}
        }
        //Push(s, temp[count]);
        //printf("%c入栈\n", temp[count]);
        Pop(s, &t);
        printf("%c出栈\n", t);
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
    //输入待判断的字符序列
    scanf("%s", str);
    if (JudgeSerial(str, n))
        printf("%s是一个正确的出栈序列\n", str);
    else
        printf("%s不是一个正确的出栈序列\n", str);
    return 0;
}
