#pragma once

#include <iostream>
#include <fstream>

using namespace std;

#include <map>
#include "globalFile.h"


class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������  key�����������¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	//��¼ԤԼ��¼
	int m_Size;
};