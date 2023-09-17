#include "speaker.h"

Speaker::Speaker()
{

}
Speaker::Speaker(string name, float score[2])
{
	m_Name = name;
	m_Score[0] = score[0];
	m_Score[1] = score[1];
}

string& Speaker::getName()
{
	return m_Name;
}

float Speaker::getScore(int i)
{
	if (i != 0 && i != 1)
	{
		return -1;
	}
	return m_Score[i];
}

bool Speaker::changeScore(float score, int i)
{
	if (i != 0 && i != 1)
	{
		return false;
	}
	m_Score[i] = score;
	return true;
}