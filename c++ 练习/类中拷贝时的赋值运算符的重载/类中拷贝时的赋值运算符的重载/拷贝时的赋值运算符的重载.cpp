#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;


class Person
{
	friend ostream* operator<<(ostream* cout, Person& p);
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person& operator=(Person& p)
	{
		//*m_Age = *p.m_Age;//实现深拷贝的方法1
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;//实现方法深拷贝的方法2
		//            （老师的做法，为什么要这样子，感觉方法1应该会更简单？？）
	}
private:

	int* m_Age;
};
ostream* operator<<(ostream* cout, Person& p)
{
	*cout << *p.m_Age<<endl;
	return cout;
}
//  打印出来为什么是：   00000267B54268E0
//                       忘记m_Age是指针了,刚开始忘记解引用
ostream& operator<<(ostream& cout, Person& p)
{
	cout << *p.m_Age;
	return cout;
}
int main()
{
	Person p1(10);
	Person p2(20);
	Person p3(30);
	p1 = p2;
	ostream* print = &cout;
	print << p1;
	cout << p1;//      000001FB1B675D60      打印的是指针

	return 0;
}