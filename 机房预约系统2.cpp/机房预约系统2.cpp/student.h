#pragma once

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "identity.h"
#include "computer.h"
#include "globalFile.h"
#include "orderFile.h"

class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��������
	vector<ComputerRoom> vCom;

	//ѧ��ѧ��
	int m_Id;
};