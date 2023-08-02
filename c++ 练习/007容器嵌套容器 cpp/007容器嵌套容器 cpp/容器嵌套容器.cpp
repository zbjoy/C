#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Person
{
public:

	Person(string name,int age)
	{
		m_Name = name;
		m_Age = age;
	}

	string m_Name;
	int m_Age;
};

ostream& operator<<(ostream& print, const Person& p)
{
	cout << "ÐÕÃû£º " << p.m_Name << "\tÄêÁä£º  " << p.m_Age << endl;
	return print;
}

void test01()
{
	vector<vector<Person>> v;
	vector<Person> vp1;
	vector<Person> vp2;
	//vector<Person> vp3;
	//vector<Person> vp4;
	//vector<Person> vp5;
	Person p1("vp1.p1", 18);
	Person p2("vp1.p2", 28);
	Person p3("vp1.p3", 38);
	Person p4("vp1.p4", 48);
	Person p5("vp1.p5", 58);
	Person p6("vp2.p6", 68);
	Person p7("vp2.p7", 78);
	Person p8("vp2.p8", 88);
	Person p9("vp2.p9", 98);
	Person p10("vp2.p10", 108);
	vp1.push_back(p1);
	vp1.push_back(p2);
	vp1.push_back(p3);
	vp1.push_back(p4);
	vp1.push_back(p5);
	vp2.push_back(p6);
	vp2.push_back(p7);
	vp2.push_back(p8);
	vp2.push_back(p9);
	vp2.push_back(p10);
	v.push_back(vp1);
	v.push_back(vp2);
	for (vector<vector<Person>>::iterator vit = v.begin(); vit != v.end(); vit++)
	{
		for (vector<Person>::iterator vpit = (*vit).begin(); vpit != (*vit).end(); vpit++)
		{
			cout << *vpit << endl;
		}
	}
}



int main()
{
	test01();
	return 0;
}