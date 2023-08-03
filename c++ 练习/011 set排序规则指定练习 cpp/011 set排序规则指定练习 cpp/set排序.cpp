#include <iostream>
#include <set>


using namespace std;

//class Person;//Ϊʲô����������ǰ�����ڷº�����
class Person
{
public:

	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

class MyCompare
{
public:
	bool operator()(const int i1,const int i2)const//ΪʲôҪ��const???
	{
		return i1 > i2;
	}

	bool operator()(const Person& p1,const  Person& p2)const
	//ΪʲôȫҪ��const�Ų�����Personǰ��const��ʲô�����ò������������const����Ϊʲô����
	{
		if (p1.m_Age == p2.m_Age)
		{
			return p1.m_Height < p2.m_Height;
		}
		return p1.m_Age < p2.m_Age;
	}
};

void printSet(set<int, MyCompare>& s)
{
	for (set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printSet(set<int>& s)
{
	for (set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

ostream& operator<<(ostream& cout,const Person& p)//Ϊʲô�����const,������cout<<*it  ???
{
	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << " ��ߣ�" << p.m_Height << endl;
	return cout;
}

void printSet(set<Person,MyCompare>& s)
{
	for (set<Person, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int, MyCompare> s;
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);
	printSet(s);
}

void test02()
{
	set<int> s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(50);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
}

//class Person
//{
//public:
//
//	Person(string name, int age, int height)
//	{
//		m_Name = name;
//		m_Age = age;
//		m_Height = height;
//	}
//
//	string m_Name;
//	int m_Age;
//	int m_Height;
//};

void test03()
{
	set<Person, MyCompare> s;
	Person p1("Tom", 12, 70);
	Person p2("Jerry", 5, 15);
	s.insert(p1);
	s.insert(p2);
	printSet(s);
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}