//����STL

#include "speechManager.h"




int main()
{
	//����������Ķ���
	SpeechManager sm;

	srand((unsigned int)time(NULL));

	//����12��ѡ�ֵĴ���
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first
	//		<< " ������" << it->second.m_Name
	//		<< " ������" << it->second.m_Score[0]
	//		<< endl;
	//}

	int choice = 0;//�����û�����

	while (true)
	{
		system("cls");
		sm.show_Menu();
		cout << "���������ѡ��\n";
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴�����¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			cout << "�����������������";
			system("cls");
			break;
		}
	}
	return 0;
}