#pragma once
#ifndef __WORKERMANAGER_H__
#define __WORKERMANAGER_H__

#include <iostream>
#include <string>
#include <fstream>
#include "worker.h"

#define FILENAME "empfile.txt"

using namespace std;

#endif


class WorkerManager
{
public:

	WorkerManager();

	void Show_Menu();

	void exitSystem();

	int m_EmpNum;

	Worker** m_EmpArray;

	void Add_Emp();

	void Show_Emp();

	void Del_Emp();

	void save();

	bool m_FileIsEmpty;

	int get_EmpNum();

	void InIt_Emp();

	int IsExist(int id);

	void Mod_Emp();

	void Find_Emp();

	void Sort_Emp();

	void Clean_File();

	~WorkerManager();

};