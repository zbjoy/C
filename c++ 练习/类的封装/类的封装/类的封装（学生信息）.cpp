#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;


class Student
{
public:
	//属性
	string m_name;
	string m_id;
	//行为
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
		cout << "姓名：" << m_name << "  学号：" << m_id<<endl;
	}
};

int main()
{
	Student s[2];
	for (int i = 0; i < 2; i++)
	{
		string name;
		string id;
		cout << "请输入学生姓名：";
		cin >> name;
		s[i].setName(name);
		cout << "请输入学生学号：";
		cin >> id;
		s[i].setId(id);
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "姓名：" << s[i].m_name << "  学号：" << s[i].m_id << endl;
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
//		cout << "请输入第"<<i+1<<"位学生的姓名：";
//		cin >> s[i].name;
//		cout << "请输入第"<<i+1<<"位学生的学号：";
//		cin >> s[i].num;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "第" << i+1 << "位学生的姓名："
//			<< s[i].name<<"\t"
//			<< "第" << i+1 << "位学生的学号："
//			<< s[i].num << "\n";
//	}
//	return 0;
//}