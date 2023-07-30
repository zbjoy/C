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
	cout << "��Ļ������ڷ������" << building->SettingRoom<<"\n";
	cout << "��Ļ������ڷ������" << building->BedRoom<<"\n";
}

Building::Building()
{
	SettingRoom = "����";
	BedRoom = "����";
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