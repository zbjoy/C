#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Test01
{

	friend ostream& operator<<(ostream& cout, Test01 test);

public:

	Test01();

	Test01& operator++();

private:

	int m_A;
	int m_B;
};

Test01::Test01()
{
	m_A = 10;
	m_B = 20;
}

Test01& Test01::operator++()
{
	m_A++;
	m_B++;
	return *this;
}

ostream& operator<<(ostream& cout, Test01 test)
{
	cout << test.m_A << "\t" << test.m_B ;
	return cout;
}

int main()
{
	Test01 test01;
	cout << test01 << endl;
	cout << ++test01 << endl;
	cout << test01 << endl;
	return 0;
}