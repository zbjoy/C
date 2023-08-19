#include "manager.h"


//默认构造
Manager::Manager()
{

}

//有参构造(管理员姓名，密码)
Manager::Manager(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	//初始化容器
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum && ifs>>c.m_NowNum)
	{
		vCom.push_back(c);
	}
	//cout << "当前机房数量为：" << vCom.size() << endl;

	ifs.close();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录！" << endl;
	cout << "\t\t\t        -----------------------------\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         1、添加账号         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         2、查看账号         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         3、查看机房         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         4、清空预约         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         0、注销登录         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t        -----------------------------\n";
}

//通过读取文件查重
//static bool checkid(int id, int select)
//{
//	ifstream ifs;
//	
//	int fId;
//	string fName;
//	string fPwd;
//	string tip;
//
//	if (select == 1)
//	{
//		ifs.open(STUDENT_FILE, ios::in);
//		tip = "学号";
//	}
//	else if (select == 2)
//	{
//		ifs.open(TEACHER_FILE, ios::in);
//		tip = "职工编号";
//	}
//	else
//	{
//		cout << "输入错误\n";
//		return false;
//	}
//
//	while (ifs >> fId && ifs >> fName && ifs >> fPwd)
//	{
//		if (fId == id)
//		{
//			cout << "已有此" << tip << endl;
//			return false;
//		}
//	}
//	return true;
//}

//通过读取容器查重
bool Manager::checkRepeat(int id, int select)
{
	if (select == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				cout << "已有此学号" << endl;
				return false;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				cout << "已有此职工号" << endl;
				return false;
			}
		}
	}

	return true;
}

//添加账号
void Manager::addPerson()
{
	while (true)
	{
		system("cls");
		this->operMenu();
		cout << "请输入添加账号的类型" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;

		string filename;
		string tip;
		ofstream ofs;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "请输入学号：";
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tip = "请输入职工编号：";
		}
		else
		{
			cout << "输入错误，请重新输入\n";
			system("pause");
			system("cls");
			continue;
		}

		ofs.open(filename, ios::out | ios::app);
		int id;
		string name;
		string pwd;

		cout << tip << endl;
		cin >> id;

		/*if (!checkid(id, select))
		{
			cout << "请重新输入\n";
			system("pause");
			system("cls");
			continue;
		}*/

		if (!checkRepeat(id, select))
		{
			cout << "请重新输入\n";
			system("pause");
			system("cls");
			continue;
		}

		cout << "请输入姓名：" << endl;
		cin >> name;

		cout << "请输入密码：" << endl;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << endl;
		cout << "添加成功" << endl;

		ofs.close();

		system("pause");
		system("cls");
		break;
	}

	this->initVector();

}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	while (true)
	{
		cout << "请选择要查看的内容：" << endl;
		cout << "1、查看所有学生" << endl;
		cout << "2、查看所有老师" << endl;
		cout << "3、查看所有成员" << endl;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "所有学生信息如下：" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);

			system("pause");
			system("cls");
			break;
		}
		else if (select == 2)
		{
			cout << "所有教师信息如下：" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);

			system("pause");
			system("cls");
			break;
		}
		else if (select == 3)
		{
			cout << "所有学生信息如下：" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			cout << endl << "所有教师信息如下：" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);

			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			continue;//也可以不加
		}
	}

}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId 
			<< " 机房最大容量：" << it->m_MaxNum 
			<< "机房现在的容量："<< it->m_NowNum
			<< endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(COMPUTER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//读取学生文件中的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "当前的学生数量为：" << vStu.size() << endl;
	ifs.close();//学生初始化

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "当前教师数量为：" << vTea.size() << endl;

	ifs.close();
}