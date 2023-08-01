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
		//cout << "MyArray有参构造调用\n";
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[m_Capacity];
	}

	
	MyArray(MyArray& arr)
	{
		//cout << "MyArray拷贝构造调用\n";
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
		//cout << "MyArray operator=重构函数用\n";
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
		//用*pAddress=*arr.m_Address可以吗？
		return *this;
	}

	//尾插法      可以到时候重构一个=号试一下可以不;
	void Push_Back(const T& val)//传的val是数组可以吗???
	{
		if (m_Capacity == m_Size)
		{
			return;
		}
		pAddress[m_Size] = val;
		m_Size++;
	}

	//尾删法
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

	//通过下标访问元素
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
		//cout << "MyArray析构调用\n";
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