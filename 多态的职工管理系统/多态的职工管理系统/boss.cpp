#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::ShowInFo()
{
	cout << "职工编号: " << m_Id
		<< "\t职工姓名:" << m_Name
		<< "\t岗位:  " << GetDeptname()
		<< "\t岗位职责: 处理公司所有的事务" << endl;
}

string Boss::GetDeptname()
{
	return string("总裁");
}