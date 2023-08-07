#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void left_move(char* arr,int k)//k为要左移的位数
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
		arr[j] = temp;//arr[j + 1] = temp;//应该是arr[j],j已经为len-1不满足条件退出上方循环
	}
}

void left_move2(char* arr, int k)//直接一次性移到位，比left_move少一个循环
{
	int i = 0;
	int len = strlen(arr);
	char temp = 0;
	while (k > len)//可以使左移的位数为大于数组位数
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
//void left_move3(char* arr,int k)//能不能通过指针来实现三步反转法
//{
//	int len = strlen(arr);
//	while (k > len)
//	{
//		k -= len;
//	}
//	char* arr1 = (char*)malloc(sizeof(k));//这样可不可以开辟出一个只能存前k个的数组指针
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
	printf("请输入你的数组：");
	scanf("%s", arr);
	printf("请输入要左移的位数：");
	scanf("%d", &n);
	left_move1(arr, n);
	printf("左移%d位后的数组为%s", n, arr);
	return 0;
}