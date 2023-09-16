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
//��ʼ��Ϊ��ջ

void  InitStack(SeqStack* s)
{
	s->top = -1;  //�ÿ�ջ
}

//�ж�ջs�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
int  StackEmpty(SeqStack* s)
{
	if (s->top == -1)
		return  1;
	else
		return  0;
}
//��Ԫ��xѹ��ջs�У�������ջ����1�����򷵻�0

int  Push(SeqStack* s, DataType  x)
{
	if (s->top == STACKSIZE - 1)     //ջ����������ջ
	{
		printf("ջ������\n");
		return  0;    //��ջʧ��
	}
	else
	{
		s->top++;               //ջ��λ�ü�1
		s->data[s->top] = x;      //x��ջ
		return  1;              //��ջ�ɹ�
	}
}

//��ջs��ջ����ջ����ͨ��ָ�����x����ջԪ�ط��أ�������ջ����1�����򷵻�0

int  Pop(SeqStack* s, DataType* x)
{
	if (s->top == -1)
	{
		//printf("ջ�ѿգ�\n");
		return  0;   //ջ�գ����ܳ�ջ
	}
	else
	{
		*x = s->data[s->top];   //ջ��Ԫ�ر�����*x��
		s->top--;      //ջ��λ�ü�1
		return  1;           //��ջ�ɹ�
	}
}

//��ȡջ��Ԫ�أ���ͨ������x������ֵ
int  GetTop(SeqStack* s, DataType* x)
{
	if (s->top == -1)
	{
		//printf("ջ�ѿգ�\n");
		return  0;   //ջ�գ���ȡʧ��
	}
	else
	{
		*x = s->data[s->top];    //ջ��Ԫ�ر�����*x�У���ʱջ��������ջ
		return  1;           //��ȡ�ɹ�
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
}  //Match����

int main()
{
	char  str[100];
	gets(str);
	int i = 0;
	//char temp = '1';
	//while ( str[i] != 's' && i < 100)Ϊʲô������str[i]��û����
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