#pragma once

#include <iostream>

using namespace std;


template <typename T>
class MyArray
{
public:

	MyArray(int capacity)
	{
		//cout << "有参构造的调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造的调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];//深拷贝

		//拷贝数据
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& arr)
	{
		//cout << "=重载函数的调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放再拷贝
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//尾插法
	void Push_Back(const T& value)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = value;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//让用户通过下标的方式访问元素
	T& operator[](int index)
	{

		return this->pAddress[index];
	}

	//返回数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组的大小
	int getSize()
	{
		return this->m_Size;
	}

	~MyArray()
	{
		//cout << "析构函数的调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:

	T* pAddress;//指向堆区开辟的真实数组

	int m_Capacity;

	int m_Size;
};