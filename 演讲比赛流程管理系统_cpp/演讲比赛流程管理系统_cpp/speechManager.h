#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <fstream>

using namespace std;

#include "speaker.h"

class SpeechManager
{
public:

	SpeechManager();

	void show_Menu();

	void exitSystem();

	void initSpeech();

	void createSpeaeker();

	void startSpeaker();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();

	void showRecord();

	void clearRecord();

	~SpeechManager();

	vector<int> v1;

	vector<int> v2;

	vector<int> vVictory;

	map<int, Speaker> m_Speaker;

	map<int, vector<string>> m_Record;

	int m_Index;

	bool fileIsEmpty;
};