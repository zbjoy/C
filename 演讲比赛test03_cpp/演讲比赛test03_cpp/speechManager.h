#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <time.h>
#include <numeric>
#include <functional>
#include <fstream>

using namespace std;

#include "speaker.h"

class SpeechManager
{
public:

	SpeechManager();

	void InitSpeech();

	void show_Menu();

	void createSpeaker();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveSpeech();

	void startSpeech();

	void loadRecord();

	void showRecord();

	void clearRecord();

	void exit();

	void error();


private:

	int Index;

	vector<int> v1;

	vector<int> v2;

	vector<int> vVictor;

	map<int, Speaker> m_Speaker;

	map<int, vector<string>> m_Record;

	bool isFileEmpty;
};