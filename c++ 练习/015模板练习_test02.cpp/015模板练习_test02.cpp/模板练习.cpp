#include <iostream>

using namespace std;

//����ģ��
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;

}

//�Զ������Ƶ�����Ҫ�Ƴ�һ�µ��������Ͳſ���ʹ��
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//mySwap(a, b);//��ȷ
	//mySwap(a, c);//����
}





//ģ������Ƴ�ȷ����T���������Ͳſ���ʹ��
template<typename T>
void func()
{
	cout << "func�ĵ���" << endl;
}





//���ú���ģ���װһ������ĺ���,���ԶԲ�ͬ�������ͽ�������
//C���Ժ������ͨ��ָ�������в�ͬ��������

template<typename T>
void mySort(T arr[],int len)
{
	//ѡ������
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
	//����char�������������
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
	//����Person��������
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

	//func();//����
	//func<int>();//��ȷ

	test02();
	test03();

	return 0;
}