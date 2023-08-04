//基于STL

#include "speechManager.h"




int main()
{
	//创建管理类的对象
	SpeechManager sm;

	srand((unsigned int)time(NULL));

	//测试12名选手的创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first
	//		<< " 姓名：" << it->second.m_Name
	//		<< " 分数：" << it->second.m_Score[0]
	//		<< endl;
	//}

	int choice = 0;//储存用户输入

	while (true)
	{
		system("cls");
		sm.show_Menu();
		cout << "请输入你的选择：\n";
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看往届记录
			sm.showRecord();
			break;
		case 3://清空比赛记录
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		default:
			cout << "输入错误，请重新输入";
			system("cls");
			break;
		}
	}
	return 0;
}