#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

class Cube
{
public:
	void setL(int L)
	{
		m_L = L;
	}
	int getL()
	{
		return m_L;
	}
	void setW(int W)
	{
		m_W = W;
	}
	int getW()
	{
		return m_W;
	}
	void setH(int H)
	{
		m_H = H;
	}
	int getH()
	{
		return m_H;
	}
	int calculateS()
	{
		return (2 * (m_H*m_W + m_L*m_W +m_H*m_L));
	}
	int calculateV()
	{
		return (m_L * m_W * m_H);
	}
	bool issamebyclasscube(Cube c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}
private:
	int m_L;
	int m_W;
	int m_H;
};

int main()
{
	Cube c[2];
	int L=0;
	int W=0;
	int H=0;
	for (int i = 0; i < 2; i++)
	{
		cout << "c"<<i+1<<"����";
		cin >> L;
		c[i].setL(L);
		cout << "c" << i + 1 << "��";
		cin >> W;
		c[i].setW(W);
		cout << "c" << i + 1 << "�ߣ�";
		cin >> H;
		c[i].setH(H);
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "����������Ϊ��" << c[i].calculateS()<<endl;
		cout << "���������Ϊ��" << c[i].calculateV()<<endl;
	}
	bool ret = c[0].issamebyclasscube(c[1]);
	if (ret)
	{
		cout << "����������\n";
	}
	else
	{
		cout << "������������\n";
	}
	ret = c[0].issamebyclasscube(c[1]);
	if (ret)
	{
		cout << "����������\n";
	}
	else
	{
		cout << "������������\n";
	}
	return 0;
}