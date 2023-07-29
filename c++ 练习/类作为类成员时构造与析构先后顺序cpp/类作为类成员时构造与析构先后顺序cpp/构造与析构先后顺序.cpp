#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Phone
{
public:
	Phone(string pname)
	{
		cout << "Phone的构造函数的调用\n";
		m_Pname = pname;
	}
	~Phone()
	{
		cout << "Phone的析构函数的调用\n";
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
		cout << "Car的构造函数的调用\n";
	}
	~Car()
	{
		cout << "Car的析构函数的调用\n";
	}
	int m_Csize;
	string m_Cname;
};

class Person
{
public:
	Person(string mname,string pname,int csize,string cname) :m_Name(mname),m_Phone(pname),m_Car(csize,cname)
	{
		cout << "Person的构造函数的调用\n";
	}
	~Person()
	{
		cout << "Person的析构函数的调用\n";
	}
	string m_Name;
	Phone m_Phone;
	Car m_Car;
};

void test01()
{
	Person zhangsan("张三", "苹果", 20, "奔驰");
	cout << zhangsan.m_Name
		<< zhangsan.m_Phone.m_Pname
		<< zhangsan.m_Car.m_Cname
		<< zhangsan.m_Car.m_Csize;
}

void test02()
{
	Person zhangsan("张三", "苹果", 20, "奔驰");
}

int main()
{
	//test01();
	test02();
//	test02测试结果：
//			Phone的构造函数的调用
//			Car的构造函数的调用
//			Person的构造函数的调用
//			Person的析构函数的调用
//			Car的析构函数的调用
//			Phone的析构函数的调用
	return 0;
}