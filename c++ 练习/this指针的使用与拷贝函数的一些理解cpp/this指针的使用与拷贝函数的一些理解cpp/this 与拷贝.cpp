#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age)//���캯��
	{
		this->age = age;
	}
	Person Personaddage(Person p)//�ӷ����������ҷ���һ�������ĺ���
	{
		this->age += p.age;
		return *this;
	}
	~Person()//��������������ͨ����ӡage���ж����ĸ�����������
	{
		cout << age << "Person�����������ĵ���\n";
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
	//���Խ����
//			20Person�����������ĵ���
//			20Person�����������ĵ���
//			50Person�����������ĵ���
//			50Person�����������ĵ���
//			20Person�����������ĵ���
//			30Person�����������ĵ���
	//���˲²⣺p1������,Ӧ��Ϊ30,
	//			p2������,Ӧ��Ϊ20��
	//          p1.Personaddage(p2)�ĵ���ʱ����������p������,Ӧ��Ϊ20
	//			p1.Personaddage(p2).Personaddage(p2)�ĵ���ʱ����������p������,Ӧ��Ϊ20
	//          p1.Personaddage(p2)�ĵ��ú󷵻صĿ�����Person����������,
	//				�Ҹо�Ӧ��Ϊ30�Ŷ԰ɣ�
	//				���Ҿ���test03���ԣ��о�Ӧ����30����Ϊʲô������50�ģ�����
	//			p1.Personaddage(p2).Personaddage(p2)�ĵ��ú󷵻صĿ�����Person������������Ӧ��Ϊ50
	//test02();
	//���Խ����
//			20Person�����������ĵ���
//			20Person�����������ĵ���
//			50
//			50Person�����������ĵ���
//			50Person�����������ĵ���
//			20Person�����������ĵ���
//			30Person�����������ĵ���
	test03();
//			20Person�����������ĵ���
// 			30
//			30Person�����������ĵ���
//			20Person�����������ĵ���
//			30Person�����������ĵ���
	return 0;
}