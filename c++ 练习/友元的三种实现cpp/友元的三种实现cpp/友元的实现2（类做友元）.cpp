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
//	friend class GoodGay;//����
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
//	cout << "���GoodGay���ڷ��ʣ�" << building->SettingRoom<<endl;
//	cout << "���GoodGay���ڷ��ʣ�" << building->BedRoom<<endl;//��Ϊ�������Կ��Է���
//}
//GoodGay::~GoodGay()
//{
//	delete building;
//}
//
//Building::Building()
//{
//	SettingRoom = "����";
//	BedRoom = "����";
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