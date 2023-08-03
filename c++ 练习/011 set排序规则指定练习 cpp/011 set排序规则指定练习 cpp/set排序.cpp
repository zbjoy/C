#include <iostream>
#include <set>


using namespace std;

//class Person;//为什么不能声明在前定义在仿函数后！
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
	bool operator()(const int i1,const int i2)const//为什么要加const???
	{
		return i1 > i2;
	}

	bool operator()(const Person& p1,const  Person& p2)const
	//为什么全要加const才不报错，Person前的const是什么意义让不报错，参数后的const又是为什么？？
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

ostream& operator<<(ostream& cout,const Person& p)//为什么必须加const,否则不能cout<<*it  ???
{
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << " 身高：" << p.m_Height << endl;
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