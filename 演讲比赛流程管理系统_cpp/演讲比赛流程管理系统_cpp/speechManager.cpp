#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();

	this->createSpeaeker();

	this->loadRecord();
}

void SpeechManager::show_Menu()
{
	cout << "************************************\n";
	cout << "******    ��ӭ�μ��ݽ�����    ******\n";
	cout << "******     1.��ʼ�ݽ�����     ******\n";
	cout << "******     2.�鿴�����¼     ******\n";
	cout << "******     3.��ձ�����¼     ******\n";
	cout << "******     0.�˳���������     ******\n";
	cout << "************************************\n";
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	this->m_Index = 1;
	this->m_Record.clear();
}

void SpeechManager::createSpeaeker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		this->v1.push_back(i + 10001);

		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}

void SpeechManager::speechContest()
{
	cout << "----------��"<<this->m_Index<<"�ֱ�����ʼ------------" << endl;
	cout << endl;

	multimap<double, int, greater<double>> groupScore;//��ʱ�������С��ɼ�

	int num = 0;//��¼��Ա����

	vector<int> v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << "  ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		//cout << "���:" << *it
		//	<< " ����:" << this->m_Speaker[*it].m_Name
		//	<< " ƽ����:" << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));//key�ǵ÷�,value�Ǳ��

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С������������£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second 
					<< " ������" << this->m_Speaker[it->second].m_Name 
					<< " �ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index - 1]
					<<endl;
			}

			//ȡ��ǰ���������뵽��һ��������
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin() ; it != groupScore.end() && count < 3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();
			cout << endl;
		}
	}
	cout << "---------��" << this->m_Index << "�ֱ�����ϣ�---------" << endl;;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "-----------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------------" << endl;

	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it
			<< " ������" << this->m_Speaker[*it].m_Name
			<< " ���䣺" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "��¼�ѱ���" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::startSpeaker()
{
	//��һ��

	//��ǩ
	this->speechDraw();

	//����
	this->speechContest();

	//��ʾ�������
	this->showScore();

	//�ڶ���
	this->m_Index++;

	//��ǩ
	this->speechDraw();

	//����
	this->speechContest();

	//��ʾ���ս��
	this->showScore();
	
	//���浽�ļ���
	this->saveRecord();

	this->initSpeech();

	this->createSpeaeker();

	this->loadRecord();

	cout << "�������������" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ������ڳ�ǩ"<<endl;
	cout << "-----------------------------------------------" << endl;
	cout << "��ǩ����ݽ�˳�����£�" << endl;

	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}

	cout << "-----------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);

	string data;
	int index = 0;

	while (ifs >> data)
	{
		//cout << data << endl;

		vector<string> v;//���6��string�ַ���

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;

	}

	ifs.close();

	//for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
	//{
	//	cout << it->first << "�ھ��ĵ÷֣�" << it->second[0] << " ������" << it->second[1] << endl;
	//}
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); ++i)
		{
			cout << "------------------------------------\n";
			cout << "��" << i + 1 << "��" << endl
				<< "�ھ��ı�ţ�" << this->m_Record[i][0]
				<< " �÷֣�" << this->m_Record[i][1] << endl;
			cout << "�Ǿ��ı�ţ�" << this->m_Record[i][2]
				<< " �÷֣�" << this->m_Record[i][3] << endl;
			cout << "�����ı�ţ�" << this->m_Record[i][4]
				<< " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "��ȷ���Ƿ���գ�" << endl;
	cout << "1��ȷ��\n2��ȡ��" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaeker();

		this->loadRecord();

		cout << "��ճɹ�" << endl;
	}

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}