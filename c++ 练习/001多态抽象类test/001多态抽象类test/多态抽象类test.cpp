#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;


class Base
{
public:

	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ\n";
	}

	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourInCup() = 0;

	//���븨��
	virtual void PutSomething() = 0;

	void Work()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Tea :public Base
{
public:
	void Brew()
	{
		cout << "�ݲ�Ҷ\n";
	}

	void PourInCup()
	{
		cout << "����ˮ����豭��\n";
	}

	void PutSomething()
	{
		cout << "��һЩ����\n";
	}

};

class Coffee:public Base
{
public:
	void Brew()
	{
		cout << "���ݿ���\n";
	}

	void PourInCup()
	{
		cout << "�����ȵ��뿧�ȱ���\n";
	}

	void PutSomething()
	{
		cout << "�����̺���\n";
	}
};

void dowork(Base* abs)
{
	abs->Work();
	delete abs;
}

int main()
{
	dowork(new Tea);
	//cout << abs->Tea::Work();
	dowork(new Coffee);
	return 0;
}