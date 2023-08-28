#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char* My_strcpy(char* dest,char* sourse)
{
	char* temp = dest;
	while (*temp != '\0')
	{
		*temp = '\0';
		temp++;
	}

	while (*sourse != '\0')
	{
		*dest = *sourse;
		dest++;
		sourse++;
	}

	return dest;
}

//void printarr(char* arr)
//{
//	char* temp = arr;
//	int len = strlen(arr);
//	int i = 0;
//	for (; i < len; ++i)
//	{
//		printf("%s", temp);// %s直接输出字符串了已经
//		temp++;
//	}
//}

int main()
{
	//int i = 1;
	//scanf("%d", &i);
	//printf("%d", i);

	char arr[10] = "123456";
	char arr1[5] = "1234";
	My_strcpy(arr, arr1);

	//printarr(arr);
	printf("%s", arr);

	return 0;
}