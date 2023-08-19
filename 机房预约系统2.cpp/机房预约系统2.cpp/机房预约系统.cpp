#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"

#include <fstream>



void mainMenu()
{
	cout << "请输入您的身份：" << endl;
	cout << "\t\t\t        -----------------------------\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         1、学生代表         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         2、老    师         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         3、管 理 员         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         0、退    出         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t        -----------------------------\n";
}

void studentMenu(Identity* &student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cout << "请输入您的操作：" << endl;
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
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
			cout << "注释成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//教师菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cout << "请输入您的选择：" << endl;
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

void managerMenu(Identity* &manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cout << "请输入您的选择：";

		cin >> select;

		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->clearFile();
		}
		else if (select == 0)//注销登录
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生登录
	{
		cout << "请输入您的学号：";
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入您的职工号：";
		cin >> id;
	}

	cout << "请输入用户名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生子菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入老师子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);

				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;

	system("pause");
	system("cls");
	return;
}


int main()
{
	int select;
	while (true)
	{
		select = 0;
		mainMenu();
		cout << "请输入您的选择:";
		cin >> select;
		//使用switch输入汉字、英语容易出现bug//为什么用if-else也不能输入汉字
		
		if (select == 1)//学生身份
		{
			LoginIn(STUDENT_FILE, 1);
		}
		else if (select == 2)//老师身份
		{
			LoginIn(TEACHER_FILE, 2);
		}
		else if (select == 3)//管理员身份
		{
			LoginIn(ADMIN_FILE, 3);
		}
		else if (select == 0)//退出
		{
			cout << "欢迎下次使用\n";
			system("pause");
			exit(0);
		}
		else
		{
			cout << "输入有误，请重新输入\n";
			system("pause");
			system("cls");
		}
	}
	
	return 0;
}