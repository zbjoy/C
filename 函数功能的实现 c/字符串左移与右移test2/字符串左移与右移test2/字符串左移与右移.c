#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void left_move(char* arr,int k)//kΪҪ���Ƶ�λ��
{
	int len = strlen(arr);
	int i = 0;
	for (; i < k; i++)
	{
		char temp = arr[0];
		int j = 0;
		for (; j < len-1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[j] = temp;//arr[j + 1] = temp;//Ӧ����arr[j],j�Ѿ�Ϊlen-1�����������˳��Ϸ�ѭ��
	}
}

void left_move2(char* arr, int k)//ֱ��һ�����Ƶ�λ����left_move��һ��ѭ��
{
	int i = 0;
	int len = strlen(arr);
	char temp = 0;
	while (k > len)//����ʹ���Ƶ�λ��Ϊ��������λ��
	{
		k -= len;
	}
	for (; i < len-k; i++)
	{
		int t = i + k;
		while (t > len)
		{
			 t -= len;
		}
		temp = arr[i];
		arr[i] = arr[t];
		arr[t] = temp;
	}
}


//void reverse(char* arr)
//{
//	int len = sizeof(arr);
//	int left = 0;
//	int right = len - 1;
//	while(left > right)
//	{
//		arr[left] = arr[right];
//		left++;
//		right--;
//	}
//}
//
//void left_move3(char* arr,int k)//�ܲ���ͨ��ָ����ʵ��������ת��
//{
//	int len = strlen(arr);
//	while (k > len)
//	{
//		k -= len;
//	}
//	char* arr1 = (char*)malloc(sizeof(k));//�����ɲ����Կ��ٳ�һ��ֻ�ܴ�ǰk��������ָ��
//	arr1 = arr;
//	char* arr2 = (char*)malloc(sizeof(len - k));
//	arr2 = arr + k;
//	reverse(arr1);
//	reverse(arr2);
//	reverse(arr);
//}

int main()
{
	char* arr=malloc(sizeof(char*));
	int n = 0;
	printf("������������飺");
	scanf("%s", arr);
	printf("������Ҫ���Ƶ�λ����");
	scanf("%d", &n);
	left_move1(arr, n);
	printf("����%dλ�������Ϊ%s", n, arr);
	return 0;
}