#pragma once

#include <iostream>
#include <vector>

using namespace std;

#include "identity.h"
#include "orderFile.h"


class Teacher :public Identity
{
public:

	//Ĭ�Ϲ���
	Teacher();

	//�вι���(ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;
};