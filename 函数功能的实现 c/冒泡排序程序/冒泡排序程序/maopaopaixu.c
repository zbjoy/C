#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void paixu(int a[],int n)
{
	int i = 0;
	for (i = 0; i < n-1; i++)
	{
		int k=0;
		for (k = 0; k < n - 1 - i; k++)
		{
			int tmp = 0;
			if (a[k] > a[k + 1])
			{
				tmp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int a[5] = {0};
	int n = 0;
	printf("请输入你想输入的数字：");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	paixu(a,5);
	int k = 0;
	for (k = 0; k < 5; k++)
	{
		printf("%d", a[k]);
	}
	return 0;
}