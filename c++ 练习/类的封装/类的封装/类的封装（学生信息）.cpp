#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;


class Student
{
public:
	//����
	string m_name;
	string m_id;
	//��Ϊ
	void setName(string name)
	{
		m_name = name;
	}
	void setId(string id)
	{
		m_id = id;
	}
	void showStudent()
	{
		cout << "������" << m_name << "  ѧ�ţ�" << m_id<<endl;
	}
};

int main()
{
	Student s[2];
	for (int i = 0; i < 2; i++)
	{
		string name;
		string id;
		cout << "������ѧ��������";
		cin >> name;
		s[i].setName(name);
		cout << "������ѧ��ѧ�ţ�";
		cin >> id;
		s[i].setId(id);
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "������" << s[i].m_name << "  ѧ�ţ�" << s[i].m_id << endl;
	}
	return 0;
}
//class student
//{
//public:
//	string name;
//	string num;
//};
//
//int main()
//{
//	student s[2];
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "�������"<<i+1<<"λѧ����������";
//		cin >> s[i].name;
//		cout << "�������"<<i+1<<"λѧ����ѧ�ţ�";
//		cin >> s[i].num;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "��" << i+1 << "λѧ����������"
//			<< s[i].name<<"\t"
//			<< "��" << i+1 << "λѧ����ѧ�ţ�"
//			<< s[i].num << "\n";
//	}
//	return 0;
//}