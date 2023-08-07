#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void* my_memmove(void* dest, void* src, size_t count)
{
	void* ret = dest;
	//������룬�Ҳ��������(�ѽ������whileѭ���ж���ʱ���ж���ִ�У����Բ���-1��ֱ����count������
	// ���룺abcdefg
	// �����a�abcdg
	//if (((char*)dest) > ((char*)src))
	//{
	//	while (count--)
	//	{
	//		*(((char*)dest) + count -1) = *(((char*)src) + count -1);
	//	}
	//}
	int n = count;
	if (dest > src)
	{
		while (count--)
		{
			*((char*)dest + n - 1) = *((char*)src + n - 1);
			((char*)dest)--;
			((char*)src)--;
		}
	}
	else
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	return ret;
}
int main()
{
	char arr1[100];
	char arr2[100];
	scanf("%s",arr1);
	scanf("%s",arr2);
	memmove(arr1 + 2, arr1, 5 * sizeof(arr1[0]));
	my_memmove(arr2 + 2, arr2, 5 * sizeof(arr2[0]));
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	return 0;
}