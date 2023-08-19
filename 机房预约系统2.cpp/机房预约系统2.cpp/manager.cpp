#include "manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���(����Ա����������)
Manager::Manager(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	//��ʼ������
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum && ifs>>c.m_NowNum)
	{
		vCom.push_back(c);
	}
	//cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	ifs.close();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
	cout << "\t\t\t        -----------------------------\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         1������˺�         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         2���鿴�˺�         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         3���鿴����         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         4�����ԤԼ         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         0��ע����¼         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t        -----------------------------\n";
}

//ͨ����ȡ�ļ�����
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
//		tip = "ѧ��";
//	}
//	else if (select == 2)
//	{
//		ifs.open(TEACHER_FILE, ios::in);
//		tip = "ְ�����";
//	}
//	else
//	{
//		cout << "�������\n";
//		return false;
//	}
//
//	while (ifs >> fId && ifs >> fName && ifs >> fPwd)
//	{
//		if (fId == id)
//		{
//			cout << "���д�" << tip << endl;
//			return false;
//		}
//	}
//	return true;
//}

//ͨ����ȡ��������
bool Manager::checkRepeat(int id, int select)
{
	if (select == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				cout << "���д�ѧ��" << endl;
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
				cout << "���д�ְ����" << endl;
				return false;
			}
		}
	}

	return true;
}

//����˺�
void Manager::addPerson()
{
	while (true)
	{
		system("cls");
		this->operMenu();
		cout << "����������˺ŵ�����" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2�������ʦ" << endl;

		string filename;
		string tip;
		ofstream ofs;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "������ѧ�ţ�";
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tip = "������ְ����ţ�";
		}
		else
		{
			cout << "�����������������\n";
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
			cout << "����������\n";
			system("pause");
			system("cls");
			continue;
		}*/

		if (!checkRepeat(id, select))
		{
			cout << "����������\n";
			system("pause");
			system("cls");
			continue;
		}

		cout << "������������" << endl;
		cin >> name;

		cout << "���������룺" << endl;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << endl;
		cout << "��ӳɹ�" << endl;

		ofs.close();

		system("pause");
		system("cls");
		break;
	}

	this->initVector();

}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	while (true)
	{
		cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
		cout << "1���鿴����ѧ��" << endl;
		cout << "2���鿴������ʦ" << endl;
		cout << "3���鿴���г�Ա" << endl;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "����ѧ����Ϣ���£�" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);

			system("pause");
			system("cls");
			break;
		}
		else if (select == 2)
		{
			cout << "���н�ʦ��Ϣ���£�" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);

			system("pause");
			system("cls");
			break;
		}
		else if (select == 3)
		{
			cout << "����ѧ����Ϣ���£�" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			cout << endl << "���н�ʦ��Ϣ���£�" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);

			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "�����������������" << endl;
			continue;//Ҳ���Բ���
		}
	}

}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId 
			<< " �������������" << it->m_MaxNum 
			<< "�������ڵ�������"<< it->m_NowNum
			<< endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(COMPUTER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰ��ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();//ѧ����ʼ��

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;

	ifs.close();
}