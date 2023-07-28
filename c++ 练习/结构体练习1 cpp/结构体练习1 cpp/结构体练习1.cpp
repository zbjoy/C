#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

typedef struct Student
{
	string name;
	int score;
}student;
typedef struct Teacher
{
	string name;
	student s[5];
}teacher;
int main() {
	teacher t[3];//teacher t[3] = { 0 };这个初始化方法导致21行代码在调试时出现问题
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "位老师的姓名：";
		cin >> t[i].name;
		//0x00007FFEDE5E7A41 (ucrtbased.dll)处(位于 结构体练习1 cpp.exe 中)引发的异常: 0xC0000005: 读取位置 0x0000000000000000 时发生访问冲突。
		cout << "请输入第" << i + 1 << "位老师所带的学生信息：\n";
		for (int j = 0; j < 5; j++)
		{
			cout << "请输入第" << j + 1 << "位学生的姓名：";
			cin >> t[i].s[j].name;
			//scanf("%s", &(t[i].s[j].name))不能用scanf读取string类型的字符串;
			//cin<<t[i].s[j]会报错，没有与之对应的“<<”  ???
			//已解决   应该是cin<<t[i].s[j].name才对
			cout << "请输入第" << j + 1 << "位学生的成绩：";
			cin >> t[i].s[j].score;
		}
		cout << "\n";
	}
	system("pause");
	system("cls");
		for (int i = 0; i < 3; i++)
		{
			cout << "带队老师为" << t[i].name << "\n";
			for (int j = 0; j < 5; j++)
			{
				cout << "第" << j +1<< "位学生姓名：" << t[i].s[j].name << "\n";
				cout << "第" << j+1 << "位学生成绩：" << t[i].s[j].score << "\n";
			}
			cout << "\n";
		}
	return 0;
}