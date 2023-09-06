#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



void test01()
{
	int a = 0x12345678;
	char i = a;
	char* p = (char*)&a;
	printf("%x", i);
	printf("%x", p[0]);
}

int main()
{
	test01();
	return 0;
}