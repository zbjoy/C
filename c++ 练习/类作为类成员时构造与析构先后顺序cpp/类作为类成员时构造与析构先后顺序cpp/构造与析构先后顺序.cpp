#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Phone
{
public:
	Phone(string pname)
	{
		cout << "Phone�Ĺ��캯���ĵ���\n";
		m_Pname = pname;
	}
	~Phone()
	{
		cout << "Phone�����������ĵ���\n";
	}
	string m_Pname;
};
class Car
{
public:
	Car(int csize,string cname)
	{
		m_Csize = csize;
		m_Cname = cname;
		cout << "Car�Ĺ��캯���ĵ���\n";
	}
	~Car()
	{
		cout << "Car�����������ĵ���\n";
	}
	int m_Csize;
	string m_Cname;
};

class Person
{
public:
	Person(string mname,string pname,int csize,string cname) :m_Name(mname),m_Phone(pname),m_Car(csize,cname)
	{
		cout << "Person�Ĺ��캯���ĵ���\n";
	}
	~Person()
	{
		cout << "Person�����������ĵ���\n";
	}
	string m_Name;
	Phone m_Phone;
	Car m_Car;
};

void test01()
{
	Person zhangsan("����", "ƻ��", 20, "����");
	cout << zhangsan.m_Name
		<< zhangsan.m_Phone.m_Pname
		<< zhangsan.m_Car.m_Cname
		<< zhangsan.m_Car.m_Csize;
}

void test02()
{
	Person zhangsan("����", "ƻ��", 20, "����");
}

int main()
{
	//test01();
	test02();
//	test02���Խ����
//			Phone�Ĺ��캯���ĵ���
//			Car�Ĺ��캯���ĵ���
//			Person�Ĺ��캯���ĵ���
//			Person�����������ĵ���
//			Car�����������ĵ���
//			Phone�����������ĵ���
	return 0;
}