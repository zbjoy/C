#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int weishu(int x)
{
	int count = 1;
	while (x/=10)
	{
		count++;
	}
	return count;
}
int cfjs(int x, int i)
{
	int t = x;
	while (i-1)
	{
		x *= t;
		i--;
	}
	return x;
}
int cifangjisuan(int i, int n)//����Ҫ��1�η�����n>0��
{
	int j = 0;
	int t = i;
	if (n >= 2)
	{
		for (j = 2; j <= n; j++)
		{
			t = t * i;
		}
	}
	return t;
}
int main()
{
	int n = 0;
	int i = 0;
	int t1 = 0;
	int t2 = 0;
	printf("������ӵڼ������ֿ�ʼ��");
	scanf("%d", &t1);
	printf("�����뵽�ڼ������ֽ�����");
	scanf("%d", &t2);
	system("cls");
	printf("����Ϊ%d��%d֮���������\n", t1, t2);
	for (i = t1; i <= t2; i++)
	{
		n=weishu(i);
		int j = 0;
		int sum = 0;
		int ret = i;
		for (j = 1; j <= n; j++)
		{
			sum += cfjs(ret % 10,n);
			ret /= 10;
		}
		if (i == sum)
		{
			printf("��������%d\n", i);
		}
	}
	return 0;
}