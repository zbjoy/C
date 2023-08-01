#include "myarray.hpp"


class Person
{
public:

	Person() {};
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	string m_Name;
	int m_Age;
};




template <typename T>
void printArray(MyArray<T>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "\n";
}

template<> void printArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i].m_Name << "\t" << arr[i].m_Age << "\n";
	}
}


void test01()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出：  \n";

	printArray(arr1);
	MyArray<int> arr2(5);
	arr2 = arr1;
	arr2.Pop_Back(3);
	cout << "arr2的打印输出：  \n";
	printArray(arr2);
	MyArray<char> arr3(5);
	for (char i = 97; i < 102; i++)
	{
		arr3.Push_Back(i);
	}
	cout << "arr3的打印输出：  \n";
	printArray(arr3);


	//MyArray<char> arr2(arr1);

	//MyArray<int> arr2(arr1);
	//MyArray<int> arr3(100);
	//arr3 = arr2;
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("孙悟空", 999);
	Person p2("韩信", 20);
	Person p3("妲己", 30);
	Person p4("赵云", 25);
	Person p5("李信", 23);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	cout << "arr的打印输出：  \n";
	printArray(arr);
}

int main()
{
	test01();
	test02();
	return 0;
}