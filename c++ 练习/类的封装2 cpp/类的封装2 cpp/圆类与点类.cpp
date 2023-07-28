#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Point
{
public:
	void setX(int x)
	{
		m_X = x;
	}
	int getX()
	{
		return m_X;
	}
	void setY(int y)
	{
		m_Y = y;
	}
	int getY()
	{
		return m_Y;
	}
private:
	int m_X;
	int m_Y;
};

class Circle
{
public:
	void setR(int r)
	{
		m_R = r;
	}
	int getR()
	{
		return m_R;
	}
	void setP(Point p)
	{
		m_P = p;
	}
	Point getP()
	{
		return m_P;
	}
private:
	int m_R;
	Point m_P;
};
bool isincircle(Circle c, Point p)
{
	if (pow(p.getX() - c.getP().getX(), 2) + pow(p.getY()-c.getP().getY(), 2) == pow(c.getR(), 2))
	{
		return true;
	}
	return false;
}

int main()
{
	Circle c;
	Point _c;
	int x;
	int y;
	int r;
	cout << "圆的x：";
	cin >> x;
	cout << "圆的y：";
	cin >> y;
	cout << "圆的半径:";
	cin >> r;
	_c.setX(x);
	_c.setY(y);
	c.setP(_c);
	c.setR(r);
	Point p[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "第" << i + 1 << "个点的x:";
		cin >> x;
		cout << "第" << i + 1 << "个点的y:";
		cin >> y;
		p[i].setX(x);
		p[i].setY(y);
	}
	bool ret;
	for (int i = 0; i < 3; i++)
	{
		ret = isincircle(c, p[i]);
		if (ret)
		{
			cout << "在圆上\n";
		}
		else
		{
			cout << "不在圆上\n";
		}
	}
	return 0;
}