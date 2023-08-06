
//bug:在修改状态后status会不见，审核中直接变为消失。

#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>

#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;


//进入学生的子菜单界面
void studentMenu(Identity* &student)
{
	while (true)
	{
		cout << "欢迎学生代表：" << ((Student*)student)->m_Name << "登录!" << endl;
		//调用学生子菜单
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//接受用户选择

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else if (select == 0)//注销登录
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入\n";
		}
	}
}

//进入教师子菜单界面
void TeacherMenu(Identity* &teacher)
{
	while (true)
	{
		//教师菜单
		teacher->operMenu();

		class::Teacher* tea = (class::Teacher*)teacher;//为什么要加class::才可以过
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
	cout << "欢迎管理员：" << manager->m_Name << "登录！" << endl;
	Sleep(1000);
	while (true)
	{
		cout << "学生当前数量：" << ((Manager*)manager)->vStu.size() << endl;
		cout << "老师当前数量：" << ((Manager*)manager)->vTea.size() <<endl;
		//调用管理员的子菜单
		manager->operMenu();

		//将父类的指针转为子类的指针
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户选项
		cin >> select;

		if (select==1)//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			//cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else if (select == 0)//注销登录
		{
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
		}

	}
}

void showMenu()
{
	cout << "请输入您的身份\n";
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            1.学生代表             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            2.老    师             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            3.管 理 员             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            0.退    出             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "请输入您的选择：\n";
}

//管理员子菜单


//登录功能         参数1   操作文件名      参数2   操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在\n";
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的id号
		string fName;//从文件中获取姓名
		string fPwd;//从文件中获取密码
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)
		{
			//测试是否可以正常输出
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;
			//cout << endl;


			//与用户输入的信息对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功!\n";
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;//从文件中获取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功!\n";
				system("pause");
				system("cls");
				person = new class::Teacher(id, name, pwd);
				//进入教师的子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证身份失败！" << endl;
	system("pause");
	system("cls");

	return;
}

int main()
{
	int select = 0;//用于接收用户选择
	while (true)
	{
		showMenu();
		cin >> select;//接收用户选择
		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用\n";
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入错误请重新选择！\n";
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}