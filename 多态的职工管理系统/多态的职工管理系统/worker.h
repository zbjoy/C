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
	
	//显示个人信息
	virtual void ShowInFo() = 0;

	//获取岗位名称
	virtual string GetDeptname() = 0;

	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//职工所在部门名称编号
};