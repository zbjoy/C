#pragma once
#ifndef __IDENTITY_H__
#define __IDENTITY_H__

#include <iostream>
#include <string>


#include "globalFile.h"

using namespace std;


#endif


//��ݳ������
class Identity
{
public:

	//�����˵�  ���麯����������ʵ��
	virtual void operMenu() = 0;

	//�û���
	string m_Name;
	//����
	string m_Pwd;
};