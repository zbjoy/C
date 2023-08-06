
//bug:���޸�״̬��status�᲻���������ֱ�ӱ�Ϊ��ʧ��

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


//����ѧ�����Ӳ˵�����
void studentMenu(Identity* &student)
{
	while (true)
	{
		cout << "��ӭѧ������" << ((Student*)student)->m_Name << "��¼!" << endl;
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//�����û�ѡ��

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else if (select == 0)//ע����¼
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������\n";
		}
	}
}

//�����ʦ�Ӳ˵�����
void TeacherMenu(Identity* &teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->operMenu();

		class::Teacher* tea = (class::Teacher*)teacher;//ΪʲôҪ��class::�ſ��Թ�
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity* &manager)
{
	cout << "��ӭ����Ա��" << manager->m_Name << "��¼��" << endl;
	Sleep(1000);
	while (true)
	{
		cout << "ѧ����ǰ������" << ((Manager*)manager)->vStu.size() << endl;
		cout << "��ʦ��ǰ������" << ((Manager*)manager)->vTea.size() <<endl;
		//���ù���Ա���Ӳ˵�
		manager->operMenu();

		//�������ָ��תΪ�����ָ��
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select==1)//����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴������Ϣ
		{
			//cout << "�鿴������Ϣ" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else if (select == 0)//ע����¼
		{
			delete manager;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}

	}
}

void showMenu()
{
	cout << "�������������\n";
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            1.ѧ������             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            2.��    ʦ             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            3.�� �� Ա             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |            0.��    ��             |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t     |                                   |\n";
	cout << "\t\t\t      ----------------------------------- \n";
	cout << "����������ѡ��\n";
}

//����Ա�Ӳ˵�


//��¼����         ����1   �����ļ���      ����2   �����������
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������\n";
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��л�ȡ����
		string fPwd;//���ļ��л�ȡ����
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)
		{
			//�����Ƿ�����������
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;
			//cout << endl;


			//���û��������Ϣ�Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�!\n";
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;//���ļ��л�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!\n";
				system("pause");
				system("cls");
				person = new class::Teacher(id, name, pwd);
				//�����ʦ���Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤���ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;
}

int main()
{
	int select = 0;//���ڽ����û�ѡ��
	while (true)
	{
		showMenu();
		cin >> select;//�����û�ѡ��
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��\n";
			system("pause");
			exit(0);
			break;
		default:
			cout << "�������������ѡ��\n";
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}