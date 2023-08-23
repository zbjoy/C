#include <iostream>

using namespace std;

//函数模板
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;

}

//自动类型推导，需要推出一致的数据类型才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//mySwap(a, b);//正确
	//mySwap(a, c);//错误
}





//模板必须推出确定的T的数据类型才可以使用
template<typename T>
void func()
{
	cout << "func的调用" << endl;
}





//利用函数模板封装一个排序的函数,可以对不同数据类型进行排序
//C语言好像可以通过指针来进行不同类型排序

template<typename T>
void mySort(T arr[],int len)
{
	//选择排序
	for (int i = 0; i < len - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[max],arr[i]);
		}
	}
}

template<typename T>
void printArray(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test02()
{
	//测试char类型数组的排序
	char charArr[] = "badcfe";
	mySort(charArr,sizeof(charArr)/sizeof(charArr[0]));
	printArray(charArr, sizeof(charArr) / sizeof(charArr[0]));
}

class Person
{
public:
	Person(char name[], int age)
	{
		m_Name = name;
		m_Age = age;
	}

	char* m_Name;
	int m_Age;
};

//template<typename T>
void mySort(Person arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max].m_Age < arr[j].m_Age)
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);
		}
		
	}
}

void printArray(Person p[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << p[i].m_Name << " " << p[i].m_Age <<endl;
	}
}

void test03()
{
	//测试Person类型数组
	char name[8] = "laowang";
	char name1[9] = "laozhang";
	Person p1(name, 18);
	Person p2(name1, 19);
	Person p[] = { p1,p2 };
	mySort(p, sizeof(p) / sizeof(p[0]));
	printArray(p, sizeof(p) / sizeof(p[0]));
}

int main()
{
	//test01();
	//double a = 10;
	//double b = 17.5;
	//mySwap<double>(a, b);
	//cout << a << "," << b;

	//func();//错误
	//func<int>();//正确

	test02();
	test03();

	return 0;
}