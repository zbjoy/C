#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;


//class Building
//{
//	friend void visit(Building& building);//条件
//public:
//	Building();
//	string SettingRoom;
//private:
//	string BedRoom;
//};
//Building::Building()
//{
//	this->SettingRoom = "客厅";
//	this->BedRoom = "卧室";
//}
//
//void visit(Building &building)
//{
//	cout << "你的好基友正在访问：" << building.SettingRoom<<endl;
//	cout << "你的好基友正在访问：" << building.BedRoom<<endl;//因为条件所以可以访问
//}
//void test()
//{
//	Building building;
//	visit(building);
//}
//
//int main1()
//{
//	test();
//	return 0;
//}