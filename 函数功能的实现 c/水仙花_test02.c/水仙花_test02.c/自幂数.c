#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int iszimishu(int a)
{
	int i = 1;
	int temp = a;
	while (temp /= 10)
	{
		i++;
	}
	int j = 0;
	for (; j < i / 2; j++)
	{
		int t = 0;
		int a1 = a;
		for (; t < i - 1; t++)
		{
			a1 /= 10;
		}
		if (a1 != a % 10)
		{
			return -1;
		}
	}
	return 1;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int ret = iszimishu(a);//�ӵ�11λ��ʼ����ʲô���������������?
	if (ret == 1)
	{
		printf("��������");
	}
	else
	{
		printf("����������");
	}
	return 0;
}