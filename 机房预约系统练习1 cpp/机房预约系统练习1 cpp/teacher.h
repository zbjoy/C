#pragma once
#ifndef __TEACHER_H__
#define __TEACHER_H__

#include "identity.h"
#include "orderFile.h"
#include <vector>

#endif

class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int empId,string name,string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//职工号
	int m_EmpId;
};