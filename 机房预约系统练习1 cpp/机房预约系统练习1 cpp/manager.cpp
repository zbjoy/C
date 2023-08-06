#include <algorithm>

#include "manager.h"
#include "globalFile.h"
#include "identity.h"

//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器并获取到所有文件中老师和学生的信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout<<"机房的数量为"<<vCom.size()<<endl;
}

//菜单界面
void Manager::operMenu()
{
	//cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            1.添加账户             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            2.查看账户             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            3.查看机房             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            4.清空预约             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            0.注销登录             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "请输入您的操作：\n";
}

//添加账号
void Manager::addPerson()
{
	while (true)
	{
		again:
		cout << "请输入添加账号的类型：" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.添加老师" << endl;
		cout << "0.退出添加" << endl;
		string fileName;
		string tip1;
		string tip2;
		string tip3;
		string errorTip;
		ofstream ofs;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip1 = "请输入学号：";
			tip2 = "请输入学生姓名：";
			tip3 = "请创建学生密码：";
			errorTip = "学号重复，请重新输入";
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip1 = "请输入职工编号：";
			tip2 = "请输入老师姓名：";
			tip3 = "请创建老师密码：";
			errorTip = "职工号重复，请重新输入";
		}
		else if (select == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			goto again;//尽量别用，但如果不用这个该怎么让它刚好返回到添加部分
		}

		ofs.open(fileName, ios::out | ios::app);
		int id;
		string name;
		string pwd;

		

		cout << tip1;

		while (true)
		{
			cin >> id;
			bool ret = checkRepeat(id, select);
			if (ret)
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}
		}

		cout << tip2;
		cin >> name;
		cout << tip3;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");

		ofs.close();

		//调用初始化容器接口，重新获取文件中的数据
		this->initVector();
		
		break;

	}
	
}

ostream& operator<<(ostream& cout,Teacher& t)//可不可以尝试做一个模板来实现Person和Teacher的打印
{
	cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd;
	return cout;
}

ostream& operator<<(ostream& cout,Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd;
	return cout;
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd<<endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd<<endl;
}

//查看账号
void Manager::showPerson()
{
	while (true)
	{
		cout << "请选择要查看的内容：" << endl;
		cout << "1.查看所有学生\n2.查找所有老师\n3.查找所有师生\n";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "所有学生信息如下：\n";
			for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
			{
				cout << *it << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2)
		{
			cout << "所有老师信息如下：\n";
			for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
			{
				cout << *it << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		else if (select == 3)
		{
			cout << "所有学生信息如下：\n";
			for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
			{
				cout << *it << endl;
			}
			cout << "所有老师信息如下：\n";
			for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
			{
				cout << *it << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "输入错误，请重新输入\n";
			system("pause");
		}
	}

	//简单写法（使用遍历算法）
	//while (true)
	//{
	//	cout << "请选择要查看的内容：" << endl;
	//	cout << "1.查看所有学生\n2.查找所有老师\n3.查找所有师生\n";
	//	int select = 0;
	//	cin >> select;
	//	if (select == 1)
	//	{
	//		cout << "所有学生信息如下：\n";
	//		for_each(vStu.begin(), vStu.end(), printStudent);
	//		system("pause");
	//		system("cls");
	//		break;
	//	}
	//	else if (select == 2)
	//	{
	//		cout << "所有老师信息如下：\n";
	//		for_each(vTea.begin(), vTea.end(), printTeacher);
	//		system("pause");
	//		system("cls");
	//		break;
	//	}
	//	else if (select == 3)
	//	{
	//		cout << "所有学生信息如下：\n";
	//		for_each(vStu.begin(), vStu.end(), printStudent);
	//		cout << "所有老师信息如下：\n";
	//		for_each(vTea.begin(), vTea.end(), printTeacher);
	//		system("pause");
	//		system("cls");
	//		break;
	//	}
	//	else
	//	{
	//		cout << "输入错误，请重新输入\n";
	//		system("pause");
	//	}
	//}
}


//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;

	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();

	//读取文件信息 学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "当前的学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取文件信息 老师
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "当前的老师数量为：" << vTea.size() << endl;
	ifs.close();
}

//检测重复      参数1 检测学号/职工号    参数2 检测类型
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
