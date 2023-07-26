#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
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
void left_move(char* a,int k)
{
	assert(a != NULL);
	int len = strlen(a);
	assert(k < len);
	reverse(a, a + k - 1);
	reverse(a + k, a + len - 1);
	reverse(a, a + len - 1);
}
int sfxzdd(char* a1, char* a2)//如果是则输出1，否则输出0
{
	int k1 = strlen(a1);
	int k2 = strlen(a2);
	if (k1 != k2)
	{
		return 0;
	}
	else if (strcmp(a1, a2) == 0)
	{
		return 1;
	}
	else
	{
		int i = 0;
		for (i = 0; i < k1; i++)
		{
			left_move(a1, 1);
			if (strcmp(a1,a2)==0)
			{
				return 1;
			}
		}
		return 0;
	}

}
int main()
{
	char a1[20] ;
	char a2[20] ;
	gets(a1);
	gets(a2);
	int t=sfxzdd(a1,a2);
	if (t == 1)
	{
		printf("可以互相旋转得到\n");
	}
	else
	{
		printf("不可以互相旋转得到\n");
	}
	return 0;
}