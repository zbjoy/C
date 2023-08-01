#pragma once
#ifndef __MYARRAY_HPP__

#include <iostream>
#include <string>

using namespace std;

#endif


template <typename T>
class MyArray
{

public:

	MyArray(int capacity)
	{
		//cout << "MyArray�вι������\n";
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[m_Capacity];
	}

	
	MyArray(MyArray& arr)
	{
		//cout << "MyArray�����������\n";
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray operator=�ع�������\n";
		if (this->pAddress != NULL)
		{
			delete pAddress;
			pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < m_Size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		//��*pAddress=*arr.m_Address������
		return *this;
	}

	//β�巨      ���Ե�ʱ���ع�һ��=����һ�¿��Բ�;
	void Push_Back(const T& val)//����val�����������???
	{
		if (m_Capacity == m_Size)
		{
			return;
		}
		pAddress[m_Size] = val;
		m_Size++;
	}

	//βɾ��
	void Pop_Back()
	{
		if (m_Size == 0)
		{
			return;
		}
		m_Size--;
	}
	void Pop_Back(int i)
	{
		for (int j = 0; j < i; j++)
		{
			if (m_Size == 0)
			{
				return;
			}
			m_Size--;
		}
	}

	//ͨ���±����Ԫ��
	T& operator[](int index)
	{
		return pAddress[index];
	}

	int getCapacity()
	{
		return m_Capacity;
	}

	int getSize()
	{
		return m_Size;
	}

	~MyArray()
	{
		//cout << "MyArray��������\n";
		if (pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
		}
	}

private:

	T* pAddress;

	int m_Capacity;
	int m_Size;
};