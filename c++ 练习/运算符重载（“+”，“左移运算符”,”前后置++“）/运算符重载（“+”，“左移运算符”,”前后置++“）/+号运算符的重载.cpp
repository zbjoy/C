#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class MyInt
{
public:

	friend ostream& operator<<(ostream& print, MyInt& p);

	MyInt operator+(MyInt& p);

	MyInt(int a, int b);//��������������ʵ�ֲ��������б��ʼ���𣿣���:m_A(a),m_B(b)�ᱨ��

private:

	int m_A;
	int m_B;
};

MyInt::MyInt(int a,int b)
{
	m_A = a;
	m_B = b;
}

MyInt MyInt::operator+(MyInt& p)
{
	MyInt temp(0,0);
	temp.m_A = m_A + p.m_A;
	temp.m_B = m_B + p.m_B;
	return temp;
}

ostream& operator<<(ostream& print, MyInt& p)
{
	print << p.m_A <<"\t"<< p.m_B;
	return print;
}

int main1()
{
	MyInt p1(3,7);
	MyInt p2(3,2);
	MyInt p3 = p1 + p2;
	cout << p3<<endl;
	return 0;
}