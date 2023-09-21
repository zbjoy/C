#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define DATAMAX 3

//void hanoi(int n, char A, char B, char C)
//{
//	if (n > 0)
//	{
//		hanoi(n - 1, A, C, B);
//		printf("%c-->%c  %d\n", A, C,n);
//		hanoi(n - 1, B, A, C);
//	}
//}
//int main()
//{
//	hanoi(4, 'A', 'B', 'C');
//	return 0;
//}

//void hanoi(int n, char A, char B, char C)
//{
//	if (n > 0)
//	{
//		hanoi(n - 1, A, C, B);
//		printf("%c-->%c\n", A, C);
//		hanoi(n - 1, B, A, C);
//	}
//}

//void hanoi(int n, char A, char B, char C)
//{
//	if (n > 0)
//	{
//		hanoi(n - 1, A, C, B);
//		printf("%c-->%c  ", A, C);
//		hanoi(n - 1, B, A, C);
//	}
//}

//void hanoi(int n, char A, char B, char C)
//{
//	if (n == 1)
//	{
//		printf("%c-->%c  ", A, C);
//	}
//	else
//	{
//		hanoi(n - 1, A, C, B);
//		printf("%c-->%c  ", A, C);
//		hanoi(n - 1, B, A, C);
//	}
//}

//void hanoi(int n, char A, char B, char C)
//{
//	if (n == 1)
//	{
//		printf("%c-->%c", A, C);
//		//return;
//	}
//	else
//	{
//		hanoi(n - 1, A, C, B);
//		printf("  %c-->%c  ", A, C);
//		hanoi(n - 1, B, A, C);
//	}
//	
//}

//void hanoi(int n, char A, char B, char C)
//{
//	if (n == 1)
//	{
//		printf("from %c to %c\n", A, C);
//	}
//	else
//	{
//		hanoi(n - 1, A, C, B);
//		printf("from %c to %c\n", A, C);
//		hanoi(n - 1, B, A, C);
//	}
//}

//void test01()//ººÅµËþ½â¾ö
//{
//	hanoi(3, 'A', 'B', 'C');
//}

typedef struct
{
	int n;
	char X, Y, Z;
}datatype;

typedef struct
{
	datatype data[DATAMAX];
	int top;
}SeqStack;

void Init_SeqStack(SeqStack* s)
{
	s->top = -1;
}

int Push_SeqStack(SeqStack* s,datatype x)
{
	if (s->top == DATAMAX - 1)
	{
		return 0;
	}
	s->top++;
	s->data[s->top] = x;
	return 1;
}

int Empty_SeqStack(SeqStack* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	return 0;
}

int Pop_SeqStack(SeqStack* s,datatype* x)
{
	if (Empty_SeqStack(s))
	{
		return 0;
	}

	*x = s->data[s->top];
	s->top--;
	return 1;
}

int GetTop_SeqStack(SeqStack* s,datatype* px)
{
	if (Empty_SeqStack(s))
	{
		return 0;
	}

	*px = s->data[s->top];
	return 1;
}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	SeqStack s;
//	datatype e;
//	char c;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Init_SeqStack(&s);
//	Push_SeqStack(&s, e);
//	while (!Empty_SeqStack(&s))
//	{
//		while (s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//		if (s.data[s.top].n == 1)
//		{
//			printf("%c-->%c\n", s.data[s.top].X, s.data[s.top].Z);
//			Pop_SeqStack(&s, &e);
//			if (!Empty_SeqStack(&s))
//			{
//				printf("%c-->%c\n", s.data[s.top].X, s.data[s.top].Z);
//				s.data[s.top].n--;
//				//Pop_SeqStack(&s, &e);
//				c = s.data[s.top].X;
//				s.data[s.top].X = s.data[s.top].Y;
//				s.data[s.top].Y = c;
//			}
//		}
//	}
//}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	char c;
//	SeqStack s;
//	Init_SeqStack(&s);
//	datatype e;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Push_SeqStack(&s, e);
//
//	while (!Empty_SeqStack(&s))
//	{
//		while (s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//
//		if (s.data[s.top].n == 1)
//		{
//			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//			Pop_SeqStack(&s, &e);
//			if (!Empty_SeqStack(&s))
//			{
//				printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//				s.data[s.top].n--;
//				c = s.data[s.top].X;
//				s.data[s.top].X = s.data[s.top].Y;
//				s.data[s.top].Y = c;
//			}
//		}
//	}
//}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	char c;
//	SeqStack s;
//	Init_SeqStack(&s);
//	datatype e;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Push_SeqStack(&s, e);
//	while (!Empty_SeqStack(&s))
//	{
//		while (s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//
//		if (s.data[s.top].n <= 1)
//		{
//			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//			Pop_SeqStack(&s, &e);
//			if (!Empty_SeqStack(&s))
//			{
//				s.data[s.top].n--;
//				printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//				c = s.data[s.top].X;
//				s.data[s.top].X = s.data[s.top].Y;
//				s.data[s.top].Y = c;
//			}
//		}
//	}
//}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	char c;
//	SeqStack s;
//	Init_SeqStack(&s);
//	datatype e;
//	datatype t;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Push_SeqStack(&s, e);
//	while (!Empty_SeqStack(&s))
//	{
//		while(s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//
//		printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//		Pop_SeqStack(&s, &t);
//		if (!Empty_SeqStack(&s))
//		{
//			s.data[s.top].n--;
//			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//			c = s.data[s.top].X;
//			s.data[s.top].X = s.data[s.top].Y;
//			s.data[s.top].Y = c;
//		}
//	}
//}

void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("%d  from %c to %c\n",n, A, C);
	}
	else
	{
		hanoi(n - 1, A, C, B);
		printf("%d  from %c to %c\n",n, A, C);
		hanoi(n - 1, B, A, C);
	}
}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	char c;
//	SeqStack s;
//	Init_SeqStack(&s);
//	datatype e;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Push_SeqStack(&s, e);
//	while (!Empty_SeqStack(&s))
//	{
//		while (s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//		if (s.data[s.top].n == 1)
//		{
//			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//			Pop_SeqStack(&s, &e);
//			if (!Empty_SeqStack(&s))
//			{
//				printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//				//if (s.data[s.top].n > 1)
//				//{
//				//	e.n = s.data[s.top].n - 1;
//				//	//c = e.X;
//				//	e.X = s.data[s.top].Y;
//				//	e.Y = s.data[s.top].X;
//				//	Push_SeqStack(&s, e);
//				//}
//				s.data[s.top].n = s.data[s.top].n - 1;
//				c = s.data[s.top].X;
//				s.data[s.top].X = s.data[s.top].Y;
//				s.data[s.top].Y = c;
//			}
//		}
//	}
//}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	char c;
//	SeqStack s;
//	Init_SeqStack(&s);
//	datatype e;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Push_SeqStack(&s, e);
//	while (!Empty_SeqStack(&s))
//	{
//		while (s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//		if (s.data[s.top].n == 1)
//		{
//			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//			Pop_SeqStack(&s,&e);
//			if (!Empty_SeqStack(&s))
//			{
//				printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//				s.data[s.top].n = s.data[s.top].n - 1;
//				c = s.data[s.top].X;
//				s.data[s.top].X = s.data[s.top].Y;
//				s.data[s.top].Y = c;
//			}
//		}
//	}
//}

//void hanoi_SeqStack(int n, char x, char y, char z)
//{
//	char c;
//	SeqStack s;
//	Init_SeqStack(&s);
//	datatype e;
//	e.n = n;
//	e.X = x;
//	e.Y = y;
//	e.Z = z;
//	Push_SeqStack(&s, e);
//	while (!Empty_SeqStack(&s))
//	{
//		while (s.data[s.top].n > 1)
//		{
//			e.n = s.data[s.top].n - 1;
//			e.X = s.data[s.top].X;
//			e.Y = s.data[s.top].Z;
//			e.Z = s.data[s.top].Y;
//			Push_SeqStack(&s, e);
//		}
//		if (s.data[s.top].n == 1)
//		{
//			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//			Pop_SeqStack(&s, &e);
//			if (!Empty_SeqStack(&s))
//			{
//				printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
//				s.data[s.top].n = s.data[s.top].n - 1;
//				c = s.data[s.top].X;
//				s.data[s.top].X = s.data[s.top].Y;
//				s.data[s.top].Y = c;
//			}
//		}
//	}
//}

void hanoi_SeqStack(int n, char x, char y, char z)
{
	char c;
	SeqStack s;
	Init_SeqStack(&s);
	datatype e;
	e.n = n;
	e.X = x;
	e.Y = y;
	e.Z = z;
	Push_SeqStack(&s, e);
	while (!Empty_SeqStack(&s))
	{
		while (s.data[s.top].n > 1)
		{
			e.n = s.data[s.top].n - 1;
			e.X = s.data[s.top].X;
			e.Y = s.data[s.top].Z;
			e.Z = s.data[s.top].Y;
			Push_SeqStack(&s, e);
		}
		printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
		Pop_SeqStack(&s, &e);
		if (!Empty_SeqStack(&s))
		{
			printf("from %c to %c\n", s.data[s.top].X, s.data[s.top].Z);
			s.data[s.top].n--;
			c = s.data[s.top].X;
			s.data[s.top].X = s.data[s.top].Y;
			//s.data[s.top].Y = c;
		}
	}
}

int main()
{
	hanoi_SeqStack(3, 'A', 'B', 'C');
	printf("\n\n");
	hanoi(3, 'A', 'B', 'C');
	return 0;
}