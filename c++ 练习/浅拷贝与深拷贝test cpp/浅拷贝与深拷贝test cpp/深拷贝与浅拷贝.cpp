#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Person
{
public:
	Person(int a,int h)
	{
		m_Age = a;
		m_Height = new int(h);//�������ʱ�ǿ��ٶ����ռ������������캯��ΪʲôҪ���ٿռ�������У������Է�ջ������
		//��Ϊ���ڹ���ʱ�����ջ������ô������ҲӦ�÷�����Ķ��壬����ջ����
	}
	Person(const Person &p)
	{
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
		//m_Height = (int*)malloc(sizeof(m_Height));
		//*m_Height=*p.m_Height;//��c�е�malloc����Ҳ����
	}
	~Person()
	{
		delete m_Height;
		m_Height = NULL;
	}
	int m_Age;
	int* m_Height;
};

int main()
{
	Person p1(18,175);
	Person p2(p1);
	cout << p2.m_Age << "  "<< * p2.m_Height << endl;
	return 0;
}