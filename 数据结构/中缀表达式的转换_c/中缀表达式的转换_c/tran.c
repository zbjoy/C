#define _CRT_SECURE_NO_WARNINGS 1

#include "tran.h"

static int Push_Char(char str[], char o)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	str[i + 1] = '\0';
	str[i] = o;
}

void trans(char str[], char exp[])
{
	int i = 0;
	char ch = str[i];
	char temp;
	SeqStack s;
	Init_SeqStack(&s);
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			Push_SeqStack(&s, &ch);
			i++;
			ch = str[i];
			break;
		case ')':
			while (!Empty_SeqStack(&s))
			{
				Pop_SeqStack(&s, &temp);
				if (temp == '(')
				{
					break;
				}
				Push_Char(exp, temp);
			}
			i++;
			ch = str[i];
			break;
		case '*':
		case '/':
			GetTop_SeqStack(&s, &temp);
			while (temp == '*' || temp == '/')
			{
				GetTop_SeqStack(&s, &temp);
				Pop_SeqStack(&s, &temp);
				Push_Char(exp, temp);
			}
			Push_SeqStack(&s, &ch);
			i++;
			ch = str[i];
			break;
		case '+':
		case '-':
			GetTop_SeqStack(&s, &temp);
			while (!Empty_SeqStack(&s) && temp != '(')
			{
				GetTop_SeqStack(&s, &temp);
				Pop_SeqStack(&s, &temp);
				Push_Char(exp, temp);
			}
			Push_SeqStack(&s, &ch);
			i++;
			ch = str[i];
			break;
		case ' ':
			i++;
			ch = str[i];
			break;
		default:
			while (ch >= '0' && ch <= '9')
			{
				Push_Char(exp, ch);
				ch = str[++i];
			}
			Push_Char(exp, '#');
			break;
		}
		//i++;
		//ch = str[i];
	}

	while (!Empty_SeqStack(&s))
	{
		Pop_SeqStack(&s, &temp);
		Push_Char(exp, temp);
	}
	Push_Char(exp, '\0');
}

float comp_value(char exp[])
{
	float d;
	float temp;
	char ch;
	int t;
	SeqStack_Int s;
	Init_SeqStack_Int(&s);
	int i = 0;
	ch = exp[i];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '+':
			Pop_SeqStack_Int(&s, &d);
			Pop_SeqStack_Int(&s, &temp);
			d = temp + d;
			Push_SeqStack_Int(&s, &d);
			break;
		case '-':
			Pop_SeqStack_Int(&s, &d);
			Pop_SeqStack_Int(&s, &temp);
			d = temp - d;
			Push_SeqStack_Int(&s, &d);
			break;
		case '*':
			Pop_SeqStack_Int(&s, &d);
			Pop_SeqStack_Int(&s, &temp);
			d = temp * d;
			Push_SeqStack_Int(&s, &d);
			break;
		case '/':
			Pop_SeqStack_Int(&s, &d);
			Pop_SeqStack_Int(&s, &temp);
			d = temp / d;
			Push_SeqStack_Int(&s, &d);
			break;
		default:
			d = 0;
			while (ch >= '0' && ch <= '9')
			{
				//d = d * 10 + ch - '0';
				d = d * 10.0f + (float)(ch - '0');
				ch = exp[++i];
			}
			Push_SeqStack_Int(&s, &d);
		}
		i++;
		ch = exp[i];
	}

	GetTop_SeqStack_Int(&s, &temp);
	//printf("\n%f", temp);
	return temp;
}