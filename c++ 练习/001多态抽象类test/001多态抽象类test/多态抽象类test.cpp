#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;


class Base
{
public:

	//煮水
	virtual void Boil()
	{
		cout << "煮开水\n";
	}

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入辅料
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
		cout << "泡茶叶\n";
	}

	void PourInCup()
	{
		cout << "将茶水倒入茶杯中\n";
	}

	void PutSomething()
	{
		cout << "放一些柠檬\n";
	}

};

class Coffee:public Base
{
public:
	void Brew()
	{
		cout << "冲泡咖啡\n";
	}

	void PourInCup()
	{
		cout << "将咖啡倒入咖啡杯中\n";
	}

	void PutSomething()
	{
		cout << "加入奶和糖\n";
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