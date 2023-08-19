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

	//默认构造
	Manager();

	//有参构造(管理员姓名，密码)
	Manager(string name,string pwd);

	//选择菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();

	//初始化容器
	void initVector();

	//通过容器查重
	bool checkRepeat(int id, int select);

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;
};