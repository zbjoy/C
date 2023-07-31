#include "workManager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"


WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在\n";
		
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空\n";
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	m_EmpNum = get_EmpNum();
	m_EmpArray = new Worker * [get_EmpNum()];
	m_FileIsEmpty = false;//临时添加
	InIt_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "*********************************\n";
	cout << "***   欢迎使用职工管理系统！  ***\n";
	cout << "*******  0.退出管理系统  ********\n";
	cout << "*******  1.增加职工信息  ********\n";
	cout << "*******  2.显示职工信息  ********\n";
	cout << "*******  3.删除离职职工  ********\n";
	cout << "*******  4.修改离职职工  ********\n";
	cout << "*******  5.查找职工信息  ********\n";
	cout << "*******  6.按照编号排序  ********\n";
	cout << "*******  7.清空所有文档  ********\n";
	cout << "*********************************\n";
}

void WorkerManager::exitSystem()
{
	cout << "退出职工管理系统\n";
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入要增加的职工数量：";
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工的编号：\n";
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：\n";
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工的岗位：\n";
			cout << "1.普通职工\n";
			cout << "2.经理\n";
			cout << "3.老板\n";
			cin >> dSelect;

			Worker* worker=NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入错误，此人添加失败n";
				break;
			}
			newSpace[m_EmpNum + i] = worker;
		}
		delete[] m_EmpArray;

		m_EmpArray = newSpace;
		m_EmpNum = newSize;

		cout << "成功添加" << addNum << "名新职工!" << endl;
		m_FileIsEmpty = false;
		save();
	}
	else
	{
		cout << "输入有误\n";
	}
}

void WorkerManager::Show_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空\n";
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->ShowInFo();
		}
	}
	
	
}

int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Id = id)
		{
			index = i;
			return i;
		}
	}
	return index;
}

void WorkerManager::Del_Emp()
{
	int num;
	cout << "请输入要删除人的编号:";
	cin >> num;
	int pos = IsExist(num);
	if (pos == -1)
	{
		cout << "查无此人\n";
	}
	else
	{
		for (int i = pos; i < m_EmpNum-1; i++)
		{
			m_EmpArray[i] = m_EmpArray[i + 1];
		}
		m_EmpNum--;
		save();
		cout << "删除成功!\n";
	}
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum;i++)
	{
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		i++;
	}
	ifs.close();
	return i;
}

void WorkerManager::InIt_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;
	int i = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		m_EmpArray[i] = worker;
		i++;
	}
	
	//关闭文件
	ifs.close();
}

void WorkerManager::Mod_Emp()
{
	cout << "请输入要修改的职工的编号：\n";
	int ret;
	cin >> ret;
	int id;
	string name;
	int dSelect;
	int i = IsExist(ret);
	if (i != -1)
	{
		cout << "查到：" << m_EmpArray[i]->m_Id << "号的员工\n";
		cout << "请输入" << m_EmpArray[i]->m_Id << "号职工的新编号：\n";
		cin >> id;
		cout << "请输入" << m_EmpArray[i]->m_Id << "号职工的新姓名：\n";
		cin >> name;
		cout << "请输入" << m_EmpArray[i]->m_Id << "号职工的新岗位：\n";
		cout << "1.普通职工\n";
		cout << "2.经理\n";
		cout << "3.老板\n";
		cin >> dSelect;

		delete m_EmpArray[i];

		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			cout << "输入错误，此人添加失败n";
			break;
		}
		m_EmpArray[i] = worker;
		cout << "修改成功!\n";
		save();
	}
	else
	{
		cout << "查无此人!\n";
	}
	
}

void WorkerManager::Find_Emp()
{

	if (m_FileIsEmpty)
	{
		cout << "文件不存在，无法查询\n";
	}
	else
	{
		cout << "请输入查找方式：\n";
		cout << "1.按职工编号查找\n";
		cout << "2.按职工姓名查找\n";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入要查找人的编号：\n";
			cin >> id;
			int ret = IsExist(id);
			if (ret == -1)
			{
				cout << "查无此人\n";
			}
			else
			{
				m_EmpArray[ret]->ShowInFo();
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找职工的姓名：\n";
			cin >> name;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查到此人\n";
					m_EmpArray[i]->ShowInFo();
					return;
				}
			}
			cout << "查无此人\n";
		}
	}


}

void WorkerManager::Clean_File()
{
	cout << "是否清空所有数据!!!\n";
	cout << "1.确认\n";
	cout << "2.返回\n";
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i] != NULL)
				{
					delete m_EmpArray[i];
					m_EmpArray[i] = NULL;
				}
			}
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
		}
	}
	else
	{
		return;
	}
}

void WorkerManager::Sort_Emp()
{
	Worker** worker = new Worker*;
	for (int i = 0; i < m_EmpNum-1; i++)
	{
		for (int j = 0; j < m_EmpNum-1-i ; j++)
		{
			if (m_EmpArray[j]->m_Id < m_EmpArray[j + 1]->m_Id)
			{
				Worker* temp = m_EmpArray[j];
				m_EmpArray[j] = m_EmpArray[j + 1];
				m_EmpArray[j + 1] = temp;
			
			/*if (m_EmpArray[max]->m_Id < m_EmpArray[j]->m_Id)
			{
				max = j;*/

				//(*worker)->m_Id = m_EmpArray[j]->m_Id;
				//(*worker)->m_Name = m_EmpArray[j]->m_Name;
				//(*worker)->m_DeptId = m_EmpArray[j]->m_DeptId;
				//m_EmpArray[j]->m_Id = m_EmpArray[j + 1]->m_Id;
				//m_EmpArray[j]->m_Name = m_EmpArray[j + 1]->m_Name;
				//m_EmpArray[j]->m_DeptId = m_EmpArray[j + 1]->m_DeptId;
				//m_EmpArray[j+1]->m_Id = (*worker)->m_Id;
				//m_EmpArray[j + 1]->m_Name = (*worker)->m_Name;
				//m_EmpArray[j + 1]->m_DeptId = (*worker)->m_DeptId;
			}
		}
		/*if (i != max)
		{
			Worker* temp = m_EmpArray[i];
			m_EmpArray[i] = m_EmpArray[max];
			m_EmpArray[max] = temp;
		}*/
	}
	save();
}

WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}