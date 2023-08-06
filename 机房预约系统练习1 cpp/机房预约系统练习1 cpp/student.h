#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "identity.h"
#include "orderFile.h"
#include "computerRoom.h"
#include <vector>

#endif


class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��� ������ѧ�š�����������
	Student(int id,string name,string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};