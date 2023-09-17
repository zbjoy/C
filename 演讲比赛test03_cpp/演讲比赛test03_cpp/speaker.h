#pragma once

#include <iostream>
#include <string>

using namespace std;

class Speaker
{
public:

	Speaker();

	Speaker(string name,float score[2]);

	string& getName();

	float getScore(int i);

	bool changeScore(float score, int i);

private:

	string m_Name;
	float m_Score[2];
};