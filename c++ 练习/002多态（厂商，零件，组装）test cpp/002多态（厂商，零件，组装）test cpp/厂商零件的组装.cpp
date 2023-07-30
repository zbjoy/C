#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>


using namespace std;



//CPU��
class CPU
{
public:

	virtual void calculate() = 0;
	
};

//�Կ���
class VideoCard
{
public:

	virtual void display() = 0;

};

//�ڴ�����
class Memory
{
public:

	virtual void storage() = 0;

};

//������
class Computer
{
public:
	Computer(CPU* cpu,VideoCard* vc,Memory* mem)
	{
		m_Cpu = cpu;
		m_VideoCard = vc;
		m_Memory = mem;
	}

	void work()
	{
		m_Cpu->calculate();
		m_VideoCard->display();
		m_Memory->storage();
	}

	~Computer()
	{
		if (m_Cpu != NULL)
		{
			delete m_Cpu;
			m_Cpu = NULL;
		}

		if (m_VideoCard != NULL)
		{
			delete m_VideoCard;
			m_VideoCard = NULL;
		}
		if (m_Memory != NULL)
		{
			delete m_Memory;
			m_Memory = NULL;
		}
	}

private:
	CPU* m_Cpu;
	VideoCard* m_VideoCard;
	Memory* m_Memory;
};

//Intel�����

class IntelCPU:public CPU
{
public:
	void calculate()
	{
		cout << "Intel��CPU��ʼ������\n";
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel���Կ���ʼ������\n";
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel���ڴ�����ʼ��ȡ�ڴ���\n";
	}
};

class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "Lenovo��CPU��ʼ������\n";
	}
};

class LenovoVideo:public VideoCard
{
	void display()
	{
		cout << "Lenovo���Կ���ʼ������\n";
	}
};

class LenovoMemory:public Memory
{
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ��ȡ�ڴ���\n";
	}
};

void test()
{
	Computer* c1 = new Computer(new IntelCPU, new IntelVideoCard, new IntelMemory);
	c1->work();
	cout << "---------------------------\n";
	delete c1;
	Computer* c2 = new Computer(new LenovoCPU, new LenovoVideo, new LenovoMemory);
	c2->work();
	cout << "---------------------------\n";
	delete c2;
	Computer* c3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	c3->work();
	cout << "---------------------------\n";
	delete c3;
}

int main()
{
	test();
	return 0;
}