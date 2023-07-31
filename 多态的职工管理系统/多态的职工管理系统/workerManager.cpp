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
		cout << "�ļ�������\n";
		
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
		cout << "�ļ�Ϊ��\n";
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	m_EmpNum = get_EmpNum();
	m_EmpArray = new Worker * [get_EmpNum()];
	m_FileIsEmpty = false;//��ʱ���
	InIt_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "*********************************\n";
	cout << "***   ��ӭʹ��ְ������ϵͳ��  ***\n";
	cout << "*******  0.�˳�����ϵͳ  ********\n";
	cout << "*******  1.����ְ����Ϣ  ********\n";
	cout << "*******  2.��ʾְ����Ϣ  ********\n";
	cout << "*******  3.ɾ����ְְ��  ********\n";
	cout << "*******  4.�޸���ְְ��  ********\n";
	cout << "*******  5.����ְ����Ϣ  ********\n";
	cout << "*******  6.���ձ������  ********\n";
	cout << "*******  7.��������ĵ�  ********\n";
	cout << "*********************************\n";
}

void WorkerManager::exitSystem()
{
	cout << "�˳�ְ������ϵͳ\n";
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "������Ҫ���ӵ�ְ��������";
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

			cout << "�������" << i + 1 << "����ְ���ı�ţ�\n";
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������\n";
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���ĸ�λ��\n";
			cout << "1.��ְͨ��\n";
			cout << "2.����\n";
			cout << "3.�ϰ�\n";
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
				cout << "������󣬴������ʧ��n";
				break;
			}
			newSpace[m_EmpNum + i] = worker;
		}
		delete[] m_EmpArray;

		m_EmpArray = newSpace;
		m_EmpNum = newSize;

		cout << "�ɹ����" << addNum << "����ְ��!" << endl;
		m_FileIsEmpty = false;
		save();
	}
	else
	{
		cout << "��������\n";
	}
}

void WorkerManager::Show_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��\n";
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
	cout << "������Ҫɾ���˵ı��:";
	cin >> num;
	int pos = IsExist(num);
	if (pos == -1)
	{
		cout << "���޴���\n";
	}
	else
	{
		for (int i = pos; i < m_EmpNum-1; i++)
		{
			m_EmpArray[i] = m_EmpArray[i + 1];
		}
		m_EmpNum--;
		save();
		cout << "ɾ���ɹ�!\n";
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
	
	//�ر��ļ�
	ifs.close();
}

void WorkerManager::Mod_Emp()
{
	cout << "������Ҫ�޸ĵ�ְ���ı�ţ�\n";
	int ret;
	cin >> ret;
	int id;
	string name;
	int dSelect;
	int i = IsExist(ret);
	if (i != -1)
	{
		cout << "�鵽��" << m_EmpArray[i]->m_Id << "�ŵ�Ա��\n";
		cout << "������" << m_EmpArray[i]->m_Id << "��ְ�����±�ţ�\n";
		cin >> id;
		cout << "������" << m_EmpArray[i]->m_Id << "��ְ������������\n";
		cin >> name;
		cout << "������" << m_EmpArray[i]->m_Id << "��ְ�����¸�λ��\n";
		cout << "1.��ְͨ��\n";
		cout << "2.����\n";
		cout << "3.�ϰ�\n";
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
			cout << "������󣬴������ʧ��n";
			break;
		}
		m_EmpArray[i] = worker;
		cout << "�޸ĳɹ�!\n";
		save();
	}
	else
	{
		cout << "���޴���!\n";
	}
	
}

void WorkerManager::Find_Emp()
{

	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڣ��޷���ѯ\n";
	}
	else
	{
		cout << "��������ҷ�ʽ��\n";
		cout << "1.��ְ����Ų���\n";
		cout << "2.��ְ����������\n";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������Ҫ�����˵ı�ţ�\n";
			cin >> id;
			int ret = IsExist(id);
			if (ret == -1)
			{
				cout << "���޴���\n";
			}
			else
			{
				m_EmpArray[ret]->ShowInFo();
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ����ְ����������\n";
			cin >> name;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "�鵽����\n";
					m_EmpArray[i]->ShowInFo();
					return;
				}
			}
			cout << "���޴���\n";
		}
	}


}

void WorkerManager::Clean_File()
{
	cout << "�Ƿ������������!!!\n";
	cout << "1.ȷ��\n";
	cout << "2.����\n";
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