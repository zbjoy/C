#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"

#include <fstream>



void mainMenu()
{
	cout << "������������ݣ�" << endl;
	cout << "\t\t\t        -----------------------------\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         1��ѧ������         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         2����    ʦ         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         3���� �� Ա         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t       |         0����    ��         |\n";
	cout << "\t\t\t       |                             |\n";
	cout << "\t\t\t        -----------------------------\n";
}

void studentMenu(Identity* &student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cout << "���������Ĳ�����" << endl;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
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
			cout << "ע�ͳɹ�" << endl;
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
		//��ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cout << "����������ѡ��" << endl;
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

void managerMenu(Identity* &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cout << "����������ѡ��";

		cin >> select;

		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else if (select == 0)//ע����¼
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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

	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ����¼
	{
		cout << "����������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)//��ʦ��¼
	{
		cout << "����������ְ���ţ�";
		cin >> id;
	}

	cout << "�������û�����";
	cin >> name;

	cout << "���������룺";
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//����ѧ���Ӳ˵�
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//������ʦ�Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;

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
		cout << "����������ѡ��:";
		cin >> select;
		//ʹ��switch���뺺�֡�Ӣ�����׳���bug//Ϊʲô��if-elseҲ�������뺺��
		
		if (select == 1)//ѧ�����
		{
			LoginIn(STUDENT_FILE, 1);
		}
		else if (select == 2)//��ʦ���
		{
			LoginIn(TEACHER_FILE, 2);
		}
		else if (select == 3)//����Ա���
		{
			LoginIn(ADMIN_FILE, 3);
		}
		else if (select == 0)//�˳�
		{
			cout << "��ӭ�´�ʹ��\n";
			system("pause");
			exit(0);
		}
		else
		{
			cout << "������������������\n";
			system("pause");
			system("cls");
		}
	}
	
	return 0;
}