#pragma once

#include <iostream>
#include <string>

using namespace std;

//身份抽象类
class Identity
{
public:

	//操作菜单
	virtual void operMenu() = 0;

	////用户名接口
	//string& name(string& name)
	//{
	//	m_Name = name;
	//	return name;
	//}

	////密码接口
	//string& pwd(string& pwd)
	//{
	//	m_Pwd = pwd;
	//	return pwd;
	//}

//protected:        protected与private有什么区别

	string m_Name;//用户名
	string m_Pwd;//密码
};