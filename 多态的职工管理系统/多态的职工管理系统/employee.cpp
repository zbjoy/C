#include "employee.h"


Employee::Employee(int id,string name,int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::ShowInFo()
{
	cout << "ְ�����: " << m_Id
		<< "\tְ������:" << m_Name
		<< "\t��λ:  " << GetDeptname()
		<< "\t��λְ��: ��ɾ�����������" << endl;
}

string Employee::GetDeptname()
{
	return string("Ա��");
}