#pragma once

#include <iostream>
#include <string>

using namespace std;

//��ݳ�����
class Identity
{
public:

	//�����˵�
	virtual void operMenu() = 0;

	////�û����ӿ�
	//string& name(string& name)
	//{
	//	m_Name = name;
	//	return name;
	//}

	////����ӿ�
	//string& pwd(string& pwd)
	//{
	//	m_Pwd = pwd;
	//	return pwd;
	//}

//protected:        protected��private��ʲô����

	string m_Name;//�û���
	string m_Pwd;//����
};