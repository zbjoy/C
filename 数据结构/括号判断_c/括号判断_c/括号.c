#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
typedef char DataType;
#define  STACKSIZE  5

typedef  struct
{
	DataType  data[STACKSIZE];
	int  top;
}SeqStack;
//初始化为空栈

void  InitStack(SeqStack* s)
{
	s->top = -1;  //置空栈
}

//判断栈s是否为空，为空返回1，否则返回0
int  StackEmpty(SeqStack* s)
{
	if (s->top == -1)
		return  1;
	else
		return  0;
}
//将元素x压入栈s中，正常入栈返回1，否则返回0

int  Push(SeqStack* s, DataType  x)
{
	if (s->top == STACKSIZE - 1)     //栈满，不能入栈
	{
		printf("栈已满！\n");
		return  0;    //入栈失败
	}
	else
	{
		s->top++;               //栈顶位置加1
		s->data[s->top] = x;      //x入栈
		return  1;              //入栈成功
	}
}

//将栈s的栈顶出栈，并通过指针变量x将顶栈元素返回，正常出栈返回1，否则返回0

int  Pop(SeqStack* s, DataType* x)
{
	if (s->top == -1)
	{
		//printf("栈已空！\n");
		return  0;   //栈空，不能出栈
	}
	else
	{
		*x = s->data[s->top];   //栈顶元素保存在*x中
		s->top--;      //栈顶位置减1
		return  1;           //出栈成功
	}
}

//读取栈顶元素，并通过参数x返回其值
int  GetTop(SeqStack* s, DataType* x)
{
	if (s->top == -1)
	{
		//printf("栈已空！\n");
		return  0;   //栈空，读取失败
	}
	else
	{
		*x = s->data[s->top];    //栈顶元素保存在*x中，此时栈顶并不出栈
		return  1;           //读取成功
	}

}

char left_Bracket[3] = { '{','[','(' };

char right_Bracket[3] = { '}',']',')' };

void tran_Bracket(char* x)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (*x == left_Bracket[i])
		{
			*x = right_Bracket[i];
		}
	}	
}

int Match(char* str)
{
	SeqStack s;
	InitStack(&s);
	char* temp = str;
	char t;
	while (*temp != '\0')
	{
		int i = 0;
		while (i < 3)
		{
			if (*temp == left_Bracket[i])
			{
				Push(&s, *temp);
				break;
			}
			i++;
		}

		t = '0';
		GetTop(&s, &t);
		tran_Bracket(&t);
		if (*temp == t)
		{
			Pop(&s, &t);
		}

		temp++;
	}

	return StackEmpty(&s);
}  //Match结束

int main()
{
	char  str[100];
	gets(str);
	int i = 0;
	//char temp = '1';
	//while ( str[i] != 's' && i < 100)为什么在这里str[i]就没有了
	//while(1)
	//{
	//	if (temp == '0')
	//	{
	//		break;
	//	}
	//	temp = getchar();
	//	str[i] = temp;
	//	i++;
	//}
	printf("%d\n", Match(str));
	return 0;
}