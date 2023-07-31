#include "manager.h"



Manager::Manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}


string Manager::GetDeptname()
{
	return string("经理");
}

void Manager::ShowInFo()
{
	cout << "职工编号: " << m_Id
		<< "\t职工姓名:" << m_Name
		<< "\t岗位:  " << GetDeptname()
		<< "\t岗位职责: 完成总裁交给的任务并向员工下发任务" << endl;
}