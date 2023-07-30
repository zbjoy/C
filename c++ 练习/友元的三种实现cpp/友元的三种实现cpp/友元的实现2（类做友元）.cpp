#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>


using namespace std;


//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();
//	~GoodGay();
//private:
//	Building* building;
//};
//
//class Building
//{
//	friend class GoodGay;//条件
//public:
//	Building();
//	string SettingRoom;
//private:
//	string BedRoom;
//};
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//void GoodGay::visit()
//{
//	cout << "你的GoodGay正在访问：" << building->SettingRoom<<endl;
//	cout << "你的GoodGay正在访问：" << building->BedRoom<<endl;//因为条件所以可以访问
//}
//GoodGay::~GoodGay()
//{
//	delete building;
//}
//
//Building::Building()
//{
//	SettingRoom = "客厅";
//	BedRoom = "卧室";
//}
//
//void test()
//{
//	GoodGay gg;
//	gg.visit();
//}
//
//int main2()
//{
//	test();
//	return 0;
//}