#include <iostream>
#include <math.h>


using namespace std;

bool ishuiwengshu1(int x)
{
	int cur = 0;
	int num = x;
	while (num)
	{
		cur = cur * 10 + num % 10;
		num /= 10;
	}
	return x == cur;
}

bool ishuiwengshu2(int x)
{
	int temp = x;
	int temp2 = x;
	int count = 1;
	while (temp /= 10)
	{
		count++;
	}
	for (int i = 0; i < count / 2; i++)
	{
		if (x / (int)pow(10, count - i - 1) % 10 != temp2 % 10)
		{
			return false;
		}
		temp2 /= 10;
	}
	return true;
}


void test1()
{
	int a = 394;
	int b = 57875;
	int c = 794707;
	if (ishuiwengshu1(a))
	{
		cout << "a是回文数\n";
	}
	if (ishuiwengshu1(b))
	{
		cout << "b是回文数\n";
	}
	if (ishuiwengshu1(c))
	{
		cout << "c是回文数\n";
	}
}

void test2()
{
	int a = 393;
	int b = 56875;
	int c = 79497;
	if (ishuiwengshu2(a))
	{
		cout << "a是回文数\n";
	}
	if (ishuiwengshu2(b))
	{
		cout << "b是回文数\n";
	}
	if (ishuiwengshu2(c))
	{
		cout << "c是回文数\n";
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}