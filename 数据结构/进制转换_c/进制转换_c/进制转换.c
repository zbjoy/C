#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define   DataType char
#define MAXSIZE1 20

typedef struct
{
	DataType data[MAXSIZE1];
	int front, rear;
}SeqQueue;

void InitQueue(SeqQueue* q)//初始化队列
{
	q->front = -1;
	q->rear = -1;
}

int DeleteQueue(SeqQueue* q, DataType* x)//出队
{
	if (q->front == q->rear)
	{
		printf(" 队列已为空，无元素可取\n");
		return 0;
	}
	else
	{
		q->front++;
		*x = q->data[q->front];
		return 1;
	}
}

int EnterQueue(SeqQueue* q, DataType x)//进队
{
	if (q->rear >= MAXSIZE1)
	{
		printf("队已满，不能插入元素\n");
		return 0;
	}
	else
	{
		q->rear++;
		q->data[q->rear] = x;
		return 1;
	}
}

int getfront(SeqQueue* q, DataType* x)//取队首元素

{
	if (q->front == q->rear)
	{
		printf(" 队列已为空，无元素可取\n");
		return 0;
	}
	else
	{
		*x = q->data[q->front + 1];
		return 1;
	}
}

char tran(int x)
{
	switch (x)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	default:
		return 'o';
	}
}

void NumConve(float x, int r, int n)//将十进制纯小数转换为r进制的纯小数，最多保留n位小数
{
	SeqQueue q;
	InitQueue(&q);
	int temp = 0;
	int i = 0;
	while (i < n)
	{
		temp = x * r;
		x *= r;
		x -= temp;
		char t = tran(temp);
		EnterQueue(&q, t);
		i++;
	}

	char t;
	printf("0.");
	while (i--)
	{
		DeleteQueue(&q, &t);
		printf("%c", t);
	}
	//while (x >= 0.0001f)
	//{
	//	temp = x * 10;
	//	x *= 10;
	//	x -= temp;
	//	char t = tran(temp);
	//	EnterQueue(&q, t);


	//	//getfront(&q, &t);
	//	//printf("%c", t);
	//}

}

int main()
{
	float x;
	int r, n;
	scanf("%f", &x);//请输入想转换的纯十进制小数
	if (x >= 1.0f)
		printf("data error\n");
	else
	{
		scanf("%d", &r);//请输入想转换的进制(2,8,16)
		scanf("%d", &n);//请输入想保留最多的小数位数
		NumConve(x, r, n);
		printf("\n");
	}
	return 0;

}