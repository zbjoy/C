#include <iostream>
#include <string>

using namespace std;

#include "myarray.hpp"

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		//利用尾插法插入数
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为：" << endl;

	printIntArray(arr1);

	MyArray<int> arr2(arr1);

	cout << "arr2的打印输出为:" << endl;

	printIntArray(arr2);

	//尾删
	arr2.Pop_Back();
	cout << "arr2尾删后的打印输出：" << endl;

	printIntArray(arr2);


	//MyArray<int> arr2(arr1);

	//MyArray<int> arr3(100);
	//arr3 = arr1;
}

class Person
{
public:

	Person() {};//必须加{}，不能Person();
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;

	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
	}
}

//测试自定义的数据类型
void test02()
{
	MyArray<Person> arr(10);

	Person p1("孙悟空", 999);
	Person p2("韩信", 20);
	Person p3("刘备", 23);
	Person p4("老王", 18);
	Person p5("老张", 19);

	//将数据插入
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArray(arr);

}

int main()
{
	test01();
	test02();
	return 0;
}