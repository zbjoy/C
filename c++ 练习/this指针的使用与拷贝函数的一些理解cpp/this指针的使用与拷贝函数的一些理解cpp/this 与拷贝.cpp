#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age)//构造函数
	{
		this->age = age;
	}
	Person Personaddage(Person p)//加法函数，并且返回一个拷贝的函数
	{
		this->age += p.age;
		return *this;
	}
	~Person()//析构函数，并且通过打印age来判断是哪个函数的析构
	{
		cout << age << "Person类析构函数的调用\n";
	}
	int age;
};

void test01()
{
	Person p1(10);
	Person p2(20);
	p1.Personaddage(p2).Personaddage(p2);
}

void test02()
{
	Person p1(10);
	Person p2(20);
	cout<<p1.Personaddage(p2).Personaddage(p2).age<<endl;
}

void test03()
{
	Person p1(10);
	Person p2(20);
	cout << p1.Personaddage(p2).age << endl;
}

int main()
{
	//test01();
	//测试结果：
//			20Person类析构函数的调用
//			20Person类析构函数的调用
//			50Person类析构函数的调用
//			50Person类析构函数的调用
//			20Person类析构函数的调用
//			30Person类析构函数的调用
	//个人猜测：p1的析构,应该为30,
	//			p2的析构,应该为20，
	//          p1.Personaddage(p2)的调用时参数拷贝的p的析构,应该为20
	//			p1.Personaddage(p2).Personaddage(p2)的调用时参数拷贝的p的析构,应该为20
	//          p1.Personaddage(p2)的调用后返回的拷贝的Person类对象的析构,
	//				我感觉应该为30才对吧，
	//				而且经过test03测试，感觉应该是30，但为什么有两个50的？？？
	//			p1.Personaddage(p2).Personaddage(p2)的调用后返回的拷贝的Person类对象的析构，应该为50
	//test02();
	//测试结果：
//			20Person类析构函数的调用
//			20Person类析构函数的调用
//			50
//			50Person类析构函数的调用
//			50Person类析构函数的调用
//			20Person类析构函数的调用
//			30Person类析构函数的调用
	test03();
//			20Person类析构函数的调用
// 			30
//			30Person类析构函数的调用
//			20Person类析构函数的调用
//			30Person类析构函数的调用
	return 0;
}