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
	m_B = "ʵ�ֳɹ�\n";
}

ostream& operator<<(ostream& cout,Test test)
{
	cout << test.m_A << "\t" << test. m_B;
	return cout;
}

int main2()
{
	Test test;//ֻ��һ��\n���У�Ϊʲô�������У�����
	cout << test;
	return 0;
}