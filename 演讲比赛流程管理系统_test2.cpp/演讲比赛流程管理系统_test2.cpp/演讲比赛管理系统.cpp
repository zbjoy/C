#include <iostream>
#include <ctime>

using namespace std;

#include "speechManager.h"



int main()
{
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	int choice = 0;

	while (true)
	{
		sm.show_Menu();

		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			sm.showRecord();
			break;
		case 3://��ռ�¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			exit(0);
		default:
			system("cls");
			break;
		}
	}

	

	system("pause");

	return 0;
}