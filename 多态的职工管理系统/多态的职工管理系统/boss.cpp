#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::ShowInFo()
{
	cout << "ְ�����: " << m_Id
		<< "\tְ������:" << m_Name
		<< "\t��λ:  " << GetDeptname()
		<< "\t��λְ��: ����˾���е�����" << endl;
}

string Boss::GetDeptname()
{
	return string("�ܲ�");
}