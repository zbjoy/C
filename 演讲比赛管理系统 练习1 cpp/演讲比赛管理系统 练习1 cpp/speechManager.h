#pragma once
#ifndef __SPEECHMANAGER_H__
#define __SPEECHMANAGER_H__

#include <iostream>
#include <vector>
#include <map>
#include <windows.h>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>

#include "speaker.h"


using namespace std;


#endif




class SpeechManager
{
public:

	//构造函数
	SpeechManager();


	//展示菜单
	void show_Menu();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//初始化容器和属性
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_Record;

	//显示往届得分
	void showRecord();

	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int> v1;

	//第一轮比赛晋级选手编号容器
	vector<int> v2;

	//胜出的前三名选手编号容器
	vector<int> vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker> m_Speaker;
	
	//存放比赛轮数
	int m_Index;

};