#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



void print(int a)
{
	cout << a << endl;
}

void test01()//int类型的读取和打印
{

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(17);
	v.push_back(30);
	//读取方法1
	//vector<int>::iterator itagain = v.begin();
	//vector<int>::iterator itend = v.end();
	//while (itagain != itend)
	//{
	//	cout << *itagain << endl;
	//	itagain++;
	//}
	//读取方法2
	//for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	//读取方法3
	for_each(v.begin(), v.end(), print);
}



class Person
{
public:
	


	Person(int age,string name)
	{
		m_Age = age;
		m_Name = name;
	}


	int m_Age;
	string m_Name;

};
//ostream& operator<<(ostream& print, MyInt& p)
//template <typename T>//会提示operator<<不明确是什么意思
//ostream& operator<<(ostream& cout, const T& p)
ostream& operator<<(ostream& cout, const Person& p)
{
	cout << p.m_Name << "\t" << p.m_Age << endl;
	return cout;
}

void printPerson(Person p)
{
	cout << p.m_Age << "\t" << p.m_Name << endl;
}

void test02()//Person类的读取和打印
{
	vector<Person> v;
	Person p1(15, "zhangsan");
	Person p2(17, "lisi");
	Person p3(30, "wangwu");
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//vector<Person>::iterator itbegin = v.begin();
	//vector<Person>::iterator itend = v.end();
	//while (itbegin != itend)
	//{
	//	cout << *itbegin << endl;
	//	itbegin++;
	//}
	//for (vector<Person>::iterator it = v.begin(); it < v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	for_each(v.begin(), v.end(),printPerson);

}

int main()
{
	test02();
	return 0;
}