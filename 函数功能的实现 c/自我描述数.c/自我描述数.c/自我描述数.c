#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int findwei(int arr)
{
	int count = 1;
	while (arr /= 10)
	{
		count++;
	}
	return count;
}

long long getmax(int val)
{
	long long i = 1;
	while (--val)
	{
		i *= 10;
	}
	return i;
}
//��obj��arr��ÿ��λ�����ֵĴ���֮��
int findnumber(long long arr,int obj,int wei)
{
	long long tmp = arr;
	int count = 0;
	int i;
	int val;
	for (i = 0; i < wei; i++)
	{
		val = arr % 10;
		arr /= 10;
		if (val == obj)
		{
			count++;
		}
	}
	return count;
}

//int findwei(int arr,int i)
//{
//	int j = 1;
//	if(j)
//	for (j = 1; j < i; j++)
//	{
//		arr /= 10;
//	}
//	return arr;
//}


//�ж�arr�ǲ�������������
//�����   ����1
int isziwomiaoshushu(long long arr,int wei)
{
	long long tmp = arr;
	int val;
	int t = wei - 1;
	int i;
	int ret;
	for (i = 0; i < wei; i++)
	{
		val = tmp % 10;
		ret = findnumber(arr, t, wei);
		if (val != ret)
		{
			return 0;
		}
		t--;
		tmp /= 10;
	}
	return 1;
}

void test01()
{

	int wei;
	scanf("%d", &wei);
	long long i = getmax(wei);
	long long j = getmax(wei+1);
	while (i < j)
	{
		if (isziwomiaoshushu(i,wei))
		{
			printf("%lld\n", i);
			//break;
		}
		i+=10;
	}
}

int main()
{
	test01();
	return 0;
}