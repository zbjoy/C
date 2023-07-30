#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;


class Test
{
	friend ostream& operator<<(ostream& cout, Test test);
public:

	Test();
private:

	int m_A;
	string m_B;
};

Test::Test()
{
	m_A = 10;
	m_B = "实现成功\n";
}

ostream& operator<<(ostream& cout,Test test)
{
	cout << test.m_A << "\t" << test. m_B;
	return cout;
}

int main2()
{
	Test test;//只有一个\n换行，为什么换了两行？？？
	cout << test;
	return 0;
}