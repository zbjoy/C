#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
void left_move(char arr[100], int k)//���ƺ���
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
void right_move(char* arr, int k)//���ƺ���
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
//����ת����
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
void left_move_sanbufa(char* a, int k)//����������
{
	assert(a != NULL);
	int len = strlen(a);
	assert(k <= len - 1);
	reverse(a, a + k - 1);
	reverse(a + k, a + len - 1);
	reverse(a, a + len - 1);
}
void right_move_sanbufa(char* a, int k)//����������
{
	assert(a != NULL);
	int len = strlen(a);
	assert(k <= len - 1);
	reverse(a + len - k, a + len - 1);
	reverse(a, a + len - k - 1);
	reverse(a, a + len - 1);
}
//���Է������룺 ABC�¸�
//               4
//        
//        �����¸�ABC?
//				ABC�¸�
//				¸�ABC ?
//				ABC�¸�
//������5ʱ���������ĸ���������ĸ��һ�����֣���һ��������������ĸ�����������ֽڣ�
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