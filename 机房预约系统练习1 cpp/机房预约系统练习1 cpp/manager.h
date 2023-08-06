#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "identity.h"
#include <vector>


#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

#endif

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name,string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ�      ����1 ���ѧ��/ְ����    ����2 �������
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//������Ϣ����
	vector<ComputerRoom> vCom;

};