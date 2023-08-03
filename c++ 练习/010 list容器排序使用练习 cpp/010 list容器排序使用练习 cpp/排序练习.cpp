#include <iostream>
#include <list>
#include <string>
#include <ctime>

using namespace std;

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

ostream& operator<<(ostream& cout,const Person& p)
{
	cout << "姓名：" << p.m_Name 
		 << "\t年龄：" << p.m_Age 
		 << "\t身高：" << p.m_Height 
		 << endl;
	return cout;
}

void printList(list<Person>& l)
{
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it;
	}
}

bool compare(Person& p1,Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age > p2.m_Age;
}

int main()
{
	srand((unsigned int)time(NULL));
	list<Person> l;
	Person p1("刘备", rand() % 21 + 50, rand() % 61 + 140);
	Person p2("曹操", rand() % 21 + 50, rand() % 61 + 140);
	Person p3("孙权", rand() % 21 + 50, rand() % 61 + 140);
	Person p4("赵云", rand() % 21 + 50, rand() % 61 + 140);
	Person p5("张飞", rand() % 21 + 50, rand() % 61 + 140);
	Person p6("关羽", rand() % 21 + 50, rand() % 61 + 140);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	cout << "排序前：\n";
	printList(l);
	l.sort(compare);
	cout << "排序后：\n";
	printList(l);
	return 0;
}