#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Person
{
public:
	Person(int a,int h)
	{
		m_Age = a;
		m_Height = new int(h);//如果拷贝时是开辟堆区空间来拷贝，构造函数为什么要开辟空间才能运行，不可以放栈区？？
		//因为它在构造时如果是栈区，那么拷贝的也应该符合类的定义，放在栈区吗？
	}
	Person(const Person &p)
	{
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
		//m_Height = (int*)malloc(sizeof(m_Height));
		//*m_Height=*p.m_Height;//用c中的malloc开辟也可以
	}
	~Person()
	{
		delete m_Height;
		m_Height = NULL;
	}
	int m_Age;
	int* m_Height;
};

int main()
{
	Person p1(18,175);
	Person p2(p1);
	cout << p2.m_Age << "  "<< * p2.m_Height << endl;
	return 0;
}