#include <iostream>
#include <time.h>

using namespace std;

#include "speechManager.h"

int main()
{
	SpeechManager sm;
	int select = 0;

	srand((unsigned int)time(NULL));

	while (true)
	{
		sm.show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º";
		cin >> select;

		switch (select)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exit();
			//break;
		default:
			sm.error();
			break;
		}
	}

	return 0;
}