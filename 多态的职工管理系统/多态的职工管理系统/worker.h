#pragma once
#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <string>


using namespace std;


#endif



class Worker
{
public:
	
	//��ʾ������Ϣ
	virtual void ShowInFo() = 0;

	//��ȡ��λ����
	virtual string GetDeptname() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ������Ʊ��
};