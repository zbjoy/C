#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>//��Ҫ�Ƿº���
#include <numeric>
#include <Windows.h>
#include <fstream>
using namespace std;
#include "speaker.h"


//�ݽ�������
class SpeechManager
{
public:

	//���캯��
	SpeechManager();

	//չʾ�˵�
	void show_Menu();

	//��ʼ������
	void initSpeech();

	//��ʼ������12��ѡ��
	void createSpeaker();

	//��ʼ���� - �������̵Ŀ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//��������
	~SpeechManager();

	//����ѡ�� ���� 12��
	vector<int> v1;

	//��һ�ֽ������� 6��
	vector<int> v2;

	//ʤ��ǰ�������� 3��
	vector<int> vVictory;

	//��ű���Լ���Ӧ�ľ���ѡ������
	map<int, Speaker> m_Speaker;

	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;

	//��¼��������
	int m_Index;

};