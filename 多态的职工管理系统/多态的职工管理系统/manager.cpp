#include "manager.h"



Manager::Manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}


string Manager::GetDeptname()
{
	return string("����");
}

void Manager::ShowInFo()
{
	cout << "ְ�����: " << m_Id
		<< "\tְ������:" << m_Name
		<< "\t��λ:  " << GetDeptname()
		<< "\t��λְ��: ����ܲý�����������Ա���·�����" << endl;
}