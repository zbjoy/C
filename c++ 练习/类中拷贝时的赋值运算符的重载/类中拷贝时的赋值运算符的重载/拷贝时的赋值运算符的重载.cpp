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
		//*m_Age = *p.m_Age;//ʵ������ķ���1
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;//ʵ�ַ�������ķ���2
		//            ����ʦ��������ΪʲôҪ�����ӣ��о�����1Ӧ�û���򵥣�����
	}
private:

	int* m_Age;
};
ostream* operator<<(ostream* cout, Person& p)
{
	*cout << *p.m_Age<<endl;
	return cout;
}
//  ��ӡ����Ϊʲô�ǣ�   00000267B54268E0
//                       ����m_Age��ָ����,�տ�ʼ���ǽ�����
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
	cout << p1;//      000001FB1B675D60      ��ӡ����ָ��

	return 0;
}