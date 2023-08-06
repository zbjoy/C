#pragma once
#ifndef __IDENTITY_H__
#define __IDENTITY_H__

#include <iostream>
#include <string>


#include "globalFile.h"

using namespace std;


#endif


//身份抽象基类
class Identity
{
public:

	//操作菜单  纯虚函数，在子类实现
	virtual void operMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};