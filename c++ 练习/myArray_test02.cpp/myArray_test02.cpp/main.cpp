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
		//����β�巨������
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;

	printIntArray(arr1);

	MyArray<int> arr2(arr1);

	cout << "arr2�Ĵ�ӡ���Ϊ:" << endl;

	printIntArray(arr2);

	//βɾ
	arr2.Pop_Back();
	cout << "arr2βɾ��Ĵ�ӡ�����" << endl;

	printIntArray(arr2);


	//MyArray<int> arr2(arr1);

	//MyArray<int> arr3(100);
	//arr3 = arr1;
}

class Person
{
public:

	Person() {};//�����{}������Person();
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
		cout << "������" << arr[i].m_Name << " ���䣺" << arr[i].m_Age << endl;
	}
}

//�����Զ������������
void test02()
{
	MyArray<Person> arr(10);

	Person p1("�����", 999);
	Person p2("����", 20);
	Person p3("����", 23);
	Person p4("����", 18);
	Person p5("����", 19);

	//�����ݲ���
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