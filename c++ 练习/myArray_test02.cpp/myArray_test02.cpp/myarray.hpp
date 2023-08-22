#pragma once

#include <iostream>

using namespace std;


template <typename T>
class MyArray
{
public:

	MyArray(int capacity)
	{
		//cout << "�вι���ĵ���" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "��������ĵ���" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];//���

		//��������
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& arr)
	{
		//cout << "=���غ����ĵ���" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ��ٿ���
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//β�巨
	void Push_Back(const T& value)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = value;
		this->m_Size++;
	}

	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//���û�ͨ���±�ķ�ʽ����Ԫ��
	T& operator[](int index)
	{

		return this->pAddress[index];
	}

	//�������������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��������Ĵ�С
	int getSize()
	{
		return this->m_Size;
	}

	~MyArray()
	{
		//cout << "���������ĵ���" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:

	T* pAddress;//ָ��������ٵ���ʵ����

	int m_Capacity;

	int m_Size;
};