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
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId,string name,string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ����
	int m_EmpId;
};