#include <iostream>
#include <time.h>

using namespace std;

#include "speechManager.h"

int main()
{
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	////≤‚ ‘¥˙¬Î
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << it->first << "  ";
	//	cout << it->second.m_Name << "  ";
	//	cout << it->second.m_Score[0] << endl;
	//}

	int choice = 0;

	while (true)
	{
		sm.show_Menu();

		cout << "«Î ‰»Îƒ˙µƒ—°‘Ò£∫" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			sm.startSpeaker();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("pause");
			break;
		}

		//system("pause");
	}
	
	return 0;
}