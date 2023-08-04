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

	//���캯��
	SpeechManager();


	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_Record;

	//��ʾ����÷�
	void showRecord();

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int> v1;

	//��һ�ֱ�������ѡ�ֱ������
	vector<int> v2;

	//ʤ����ǰ����ѡ�ֱ������
	vector<int> vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker> m_Speaker;
	
	//��ű�������
	int m_Index;

};