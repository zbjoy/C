#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

#include "identity.h"
#include "globalFile.h"
#include "teacher.h"
#include "student.h"
#include "computer.h"


class Manager :public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���(����Ա����������)
	Manager(string name,string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();

	//��ʼ������
	void initVector();

	//ͨ����������
	bool checkRepeat(int id, int select);

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
};