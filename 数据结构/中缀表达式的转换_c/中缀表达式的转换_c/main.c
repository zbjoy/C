#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "SeqStack.h"
#include "tran.h"

//void trans(char str[], char exp[])
//{
//    char ch;      
//    OP op;     /*op为一个存放运算符的栈*/
//    int i = 0, t = 0;
//    op.top = -1;        /*栈初始化为空栈*/
//    ch = str[i]; i++;   /*取第一个字符，同时移动下标，为取下一个字符准备*/
//    while (ch != '\0') /*只要中缀表达式还未扫描结束*/
//    {
//        switch (ch)  /*对所取的字符判断是什么符号，以便决定处理办法*/
//        {
//        case '(': op.top++; op.data[op.top] = ch; break; //若是左括号，入栈
//        case ')': /*若是右括号，则一一出栈，直到遇到左括号为止*/
//            while (op.data[op.top] != '(')
//            {
//                exp[t] = op.data[op.top];  op.top--; t++;
//            }
//            op.top--; break;    /*左括号出栈，但并不给exp中赋值*/
//        case '+': /*遇到加减号，出栈，直到栈空或者栈顶是左括号为止,继续执行乘除号的分支，之后进栈*/
//        case '-': while (op.top != -1 && op.data[op.top] != '(')
//        {
//            exp[t] = op.data[op.top];    op.top--;     t++;
//        }
//                op.top++; op.data[op.top] = ch; break; /*然后该+-号元素进栈*/
//        case '*':/*遇到乘除号，出栈直到栈顶不等于乘和除号为止*/
//        case '/':    while (op.data[op.top] == '*' || op.data[op.top] == '/')
//        {
//            exp[t] = op.data[op.top];    op.top--;    t++;
//        }
//                op.top++; op.data[op.top] = ch; break; //然后该乘除号元素进栈
//        case ' ': break;/*遇到空格，什么也不做*/
//        default:    /*对于数字字符直接赋值到exp,直到非数字字符为止*/
//            while (ch >= '0' && ch <= '9')
//            {
//                exp[t] = ch;  	 t++;  ch = str[i];    i++;
//            }
//            i--;   /*因上述循环多取一个字符，故下标减１*/
//            exp[t] = '#';    t++;
//        }  /*一个操作数之后加一个#做为间隔符，switch语句结束
//          ch=str[i];  i++;       /*继续读取下一个字符*/
//    } //while语句结束
//    while (op.top != -1)/*若表达式扫描结束，栈未空，则一一出栈传给exp*/
//    {
//        exp[t] = op.data[op.top];
//        op.top--;
//        t++;
//    }
//    exp[t] = '\0';/*给exp加字符串结束标志*/
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