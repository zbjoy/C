#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "SeqStack.h"
#include "tran.h"

//void trans(char str[], char exp[])
//{
//    char ch;      
//    OP op;     /*opΪһ������������ջ*/
//    int i = 0, t = 0;
//    op.top = -1;        /*ջ��ʼ��Ϊ��ջ*/
//    ch = str[i]; i++;   /*ȡ��һ���ַ���ͬʱ�ƶ��±꣬Ϊȡ��һ���ַ�׼��*/
//    while (ch != '\0') /*ֻҪ��׺���ʽ��δɨ�����*/
//    {
//        switch (ch)  /*����ȡ���ַ��ж���ʲô���ţ��Ա��������취*/
//        {
//        case '(': op.top++; op.data[op.top] = ch; break; //���������ţ���ջ
//        case ')': /*���������ţ���һһ��ջ��ֱ������������Ϊֹ*/
//            while (op.data[op.top] != '(')
//            {
//                exp[t] = op.data[op.top];  op.top--; t++;
//            }
//            op.top--; break;    /*�����ų�ջ����������exp�и�ֵ*/
//        case '+': /*�����Ӽ��ţ���ջ��ֱ��ջ�ջ���ջ����������Ϊֹ,����ִ�г˳��ŵķ�֧��֮���ջ*/
//        case '-': while (op.top != -1 && op.data[op.top] != '(')
//        {
//            exp[t] = op.data[op.top];    op.top--;     t++;
//        }
//                op.top++; op.data[op.top] = ch; break; /*Ȼ���+-��Ԫ�ؽ�ջ*/
//        case '*':/*�����˳��ţ���ջֱ��ջ�������ڳ˺ͳ���Ϊֹ*/
//        case '/':    while (op.data[op.top] == '*' || op.data[op.top] == '/')
//        {
//            exp[t] = op.data[op.top];    op.top--;    t++;
//        }
//                op.top++; op.data[op.top] = ch; break; //Ȼ��ó˳���Ԫ�ؽ�ջ
//        case ' ': break;/*�����ո�ʲôҲ����*/
//        default:    /*���������ַ�ֱ�Ӹ�ֵ��exp,ֱ���������ַ�Ϊֹ*/
//            while (ch >= '0' && ch <= '9')
//            {
//                exp[t] = ch;  	 t++;  ch = str[i];    i++;
//            }
//            i--;   /*������ѭ����ȡһ���ַ������±����*/
//            exp[t] = '#';    t++;
//        }  /*һ��������֮���һ��#��Ϊ�������switch������
//          ch=str[i];  i++;       /*������ȡ��һ���ַ�*/
//    } //while������
//    while (op.top != -1)/*�����ʽɨ�������ջδ�գ���һһ��ջ����exp*/
//    {
//        exp[t] = op.data[op.top];
//        op.top--;
//        t++;
//    }
//    exp[t] = '\0';/*��exp���ַ���������־*/
//}
//extern void trans()

void test()
{
    char str[] = "1+2/2+(3+5)*3";
    char exp[100] = {0};
    trans(str, exp);
    printf("%s", exp);
    //printf("\n%d",comp_value(exp));
    //printf("\n%f", comp_value(exp));
    float t = comp_value(exp);
    printf("\n%f", t);
}



int main()
{
    test();
	return 0;
}