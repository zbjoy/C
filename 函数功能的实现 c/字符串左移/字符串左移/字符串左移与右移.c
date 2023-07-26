#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
void left_move(char arr[100], int k)//左移函数
{
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		int j = 0;
			char tmp = arr[0];
		for (j=0;j<len-1;j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tmp;
	}
}
void right_move(char* arr, int k)//右移函数
{
	assert(arr!=NULL);
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		int j = 0;
		char tmp = *(arr+len-1);
		for (j = len-1 ; j > 0 ; j--)
		{
			*(arr + j) = *(arr + j - 1);
		}
		*arr = tmp;
	}
}
//三步转换法
void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move_sanbufa(char* a, int k)//三步法左移
{
	assert(a != NULL);
	int len = strlen(a);
	assert(k <= len - 1);
	reverse(a, a + k - 1);
	reverse(a + k, a + len - 1);
	reverse(a, a + len - 1);
}
void right_move_sanbufa(char* a, int k)//三步法右移
{
	assert(a != NULL);
	int len = strlen(a);
	assert(k <= len - 1);
	reverse(a + len - k, a + len - 1);
	reverse(a, a + len - k - 1);
	reverse(a, a + len - 1);
}
//调试发现输入： ABC德福
//               4
//        
//        输出：赂BC?
//				ABC德福
//				赂BC ?
//				ABC德福
//而输入5时则左移了四个（三个字母与一个汉字），一个汉字算两个字母（即算两个字节）
int main()
{
	char arr[100] = { 0 };
	int k = 0;
	gets(arr);
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	right_move(arr, k);
	printf("%s\n", arr);
	left_move_sanbufa(arr, k);
	printf("%s\n", arr);
	right_move_sanbufa(arr, k);
	printf("%s", arr);
	return 0;
}