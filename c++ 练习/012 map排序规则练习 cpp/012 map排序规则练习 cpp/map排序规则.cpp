#include <iostream>
#include <map>
#include <string>

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

class Compare
{
public:

	bool operator()(const Person& p1,const Person& p2)const
	{
		if (p1.m_Age == p2.m_Age)
		{
			return p1.m_Height > p2.m_Height;
		}
		return p1.m_Age > p2.m_Age;
	}
};

ostream& operator<<(ostream& cout,const Person& p)//Ϊʲô������const ???
{
	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << " ��ߣ�" << p.m_Height;
	return cout;
}

void printMap(map<Person, Person, Compare>& m)
{
	for (map<Person, Person, Compare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key="<<(*it).first << "\t value=" << (*it).second << endl;
	}
}

int main()
{
	map<Person, Person, Compare> m;
	//m.insert(pair<Person, Person>(("����", 18, 170), ("����", 18, 170)));
	//m.insert(make_pair(Person p1("����", 18, 170),Person p1("����", 18, 170)));
	Person p1("����", 28, 150);
	Person p2("����", 18, 170);
	Person p3("����", 20, 160);
	Person p4("����", 50, 173);
	Person p5("����", 20, 165);
	m.insert(make_pair(p1, p1));
	m.insert(pair<Person,Person>(p2, p2));
	//m.insert(map<Person,Person,Compare>(p3, p3));
	m.insert(pair<Person, Person>(p3, p3));
	m.insert(make_pair(p4, p4));
	m.insert(make_pair(p5, p5));
	printMap(m);
	return 0;
}