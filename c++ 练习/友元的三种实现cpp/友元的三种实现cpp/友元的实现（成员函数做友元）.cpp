#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>


using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();
	void visit();
private:
	Building* building;
};

class Building
{
	friend void GoodGay::visit();
public:
	Building();
	string SettingRoom;
private:
	string BedRoom;
};

GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::visit()
{
	cout << "你的基友正在访问你的" << building->SettingRoom<<"\n";
	cout << "你的基友正在访问你的" << building->BedRoom<<"\n";
}

Building::Building()
{
	SettingRoom = "客厅";
	BedRoom = "卧室";
}

void test()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test();
	return 0;
}