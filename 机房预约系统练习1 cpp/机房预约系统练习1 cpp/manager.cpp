#include <algorithm>

#include "manager.h"
#include "globalFile.h"
#include "identity.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ����������ȡ�������ļ�����ʦ��ѧ������Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout<<"����������Ϊ"<<vCom.size()<<endl;
}

//�˵�����
void Manager::operMenu()
{
	//cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            1.����˻�             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            2.�鿴�˻�             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            3.�鿴����             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            4.���ԤԼ             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            0.ע����¼             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "���������Ĳ�����\n";
}

//����˺�
void Manager::addPerson()
{
	while (true)
	{
		again:
		cout << "����������˺ŵ����ͣ�" << endl;
		cout << "1.���ѧ��" << endl;
		cout << "2.�����ʦ" << endl;
		cout << "0.�˳����" << endl;
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
			tip1 = "������ѧ�ţ�";
			tip2 = "������ѧ��������";
			tip3 = "�봴��ѧ�����룺";
			errorTip = "ѧ���ظ�������������";
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip1 = "������ְ����ţ�";
			tip2 = "��������ʦ������";
			tip3 = "�봴����ʦ���룺";
			errorTip = "ְ�����ظ�������������";
		}
		else if (select == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			goto again;//�������ã�����������������ô�����պ÷��ص���Ӳ���
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
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");

		ofs.close();

		//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
		this->initVector();
		
		break;

	}
	
}

ostream& operator<<(ostream& cout,Teacher& t)//�ɲ����Գ�����һ��ģ����ʵ��Person��Teacher�Ĵ�ӡ
{
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd;
	return cout;
}

ostream& operator<<(ostream& cout,Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd;
	return cout;
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd<<endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd<<endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	while (true)
	{
		cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
		cout << "1.�鿴����ѧ��\n2.����������ʦ\n3.��������ʦ��\n";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����ѧ����Ϣ���£�\n";
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
			cout << "������ʦ��Ϣ���£�\n";
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
			cout << "����ѧ����Ϣ���£�\n";
			for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
			{
				cout << *it << endl;
			}
			cout << "������ʦ��Ϣ���£�\n";
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
			cout << "�����������������\n";
			system("pause");
		}
	}

	//��д����ʹ�ñ����㷨��
	//while (true)
	//{
	//	cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
	//	cout << "1.�鿴����ѧ��\n2.����������ʦ\n3.��������ʦ��\n";
	//	int select = 0;
	//	cin >> select;
	//	if (select == 1)
	//	{
	//		cout << "����ѧ����Ϣ���£�\n";
	//		for_each(vStu.begin(), vStu.end(), printStudent);
	//		system("pause");
	//		system("cls");
	//		break;
	//	}
	//	else if (select == 2)
	//	{
	//		cout << "������ʦ��Ϣ���£�\n";
	//		for_each(vTea.begin(), vTea.end(), printTeacher);
	//		system("pause");
	//		system("cls");
	//		break;
	//	}
	//	else if (select == 3)
	//	{
	//		cout << "����ѧ����Ϣ���£�\n";
	//		for_each(vStu.begin(), vStu.end(), printStudent);
	//		cout << "������ʦ��Ϣ���£�\n";
	//		for_each(vTea.begin(), vTea.end(), printTeacher);
	//		system("pause");
	//		system("cls");
	//		break;
	//	}
	//	else
	//	{
	//		cout << "�����������������\n";
	//		system("pause");
	//	}
	//}
}


//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " �������������" << it->m_MaxNum << endl;

	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();

	//��ȡ�ļ���Ϣ ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰ��ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ�ļ���Ϣ ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ����ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����ظ�      ����1 ���ѧ��/ְ����    ����2 �������
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
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
		//�����ʦ
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
