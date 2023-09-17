#include "speechManager.h"

SpeechManager::SpeechManager()
{
	InitSpeech();

	createSpeaker();

	loadRecord();
}

void SpeechManager::InitSpeech()
{
	v1.clear();
	v2.clear();
	vVictor.clear();
	m_Speaker.clear();

	Index = 1;
}

void SpeechManager::show_Menu()
{
	cout << "************************************\n";
	cout << "******    欢迎参加演讲比赛    ******\n";
	cout << "******     1.开始演讲比赛     ******\n";
	cout << "******     2.查看往届记录     ******\n";
	cout << "******     3.清空比赛记录     ******\n";
	cout << "******     0.退出比赛程序     ******\n";
	cout << "************************************\n";
	cout << endl;
}

void SpeechManager::createSpeaker()
{
	string nameNeed = "ABCDEFGHIJKL";
	float score[2] = {0.0f,0.0f};

	for (int i = 0; i < 12; i++)
	{
		string name = "选手";
		name += nameNeed[i];
		//cout << name << endl;
		Speaker s(name, score);
		v1.push_back(i + 10001);
		m_Speaker.insert(make_pair(i + 10001, s));
	}

}

void SpeechManager::speechDraw()
{
	cout << "第<<" << this->Index << ">>轮比赛正在抽签" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "抽签后的演讲顺序如下：" << endl;

	vector<int> v;
	v.clear();

	if (this->Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());

		v = v1;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());

		v = v2;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

}

void SpeechManager::speechContest()
{
	cout << "----------第" << this->Index << "轮比赛开始------------" << endl;
	cout << endl;

	//multimap<float, int, greater<float>()> groupScore;
	multimap<float, int, greater<float>> groupScore;
	groupScore.clear();

	vector<int> v;
	int num = 0;

	if (Index == 1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<float> d;
		d.clear();

		for (int i = 0; i < 12; i++)
		{
			float score = (rand() % 401 + 600) / 10.0f;
			//cout << score << "  ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<float>());

		d.pop_back();
		d.pop_front();

		float sum = accumulate(d.begin(), d.end(), 0.0f);
		//cout << sum << " ";
		float avg = sum / (float)d.size();

		m_Speaker[*it].changeScore(avg, Index - 1);//为什么没有Speaker()这个构造函数会使它报错？？？

		groupScore.insert(make_pair(avg,*it));

		if (!(num % 6))
		{
			cout << "第" << num / 6 << "组的名次如下" << endl;
			//for (multimap<float, int, greater<float>()>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			for (multimap<float, int, greater<float>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "选手编号：" << it->second << "  ";
				cout << "选手姓名：" << m_Speaker[it->second].getName() << "  ";
				cout << "选手成绩：" << m_Speaker[it->second].getScore(Index - 1) << endl;
			}

			int count = 0;

			for (multimap<float, int, greater<float>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++,count++)
			{
				if (Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictor.push_back(it->second);
				}
			}

			groupScore.clear();
		}
	}

	cout << "---------第" << this->Index << "轮比赛完毕！---------" << endl;;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "-----------第" << this->Index << "轮晋级选手信息如下：-----------------" << endl;

	vector<int> v;
	if (this->Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictor;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << "  ";
		cout << "选手姓名：" << m_Speaker[*it].getName() << "  ";
		cout << "选手成绩：" << m_Speaker[*it].getScore(Index - 1) << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::saveSpeech()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = vVictor.begin(); it != vVictor.end(); it++)
	{
		//ofs << *it << ",";
		//ofs << m_Speaker[*it].getName() << ",";
		//ofs << m_Speaker[*it].getScore(1) <<","<< endl;
		ofs << *it << "," << m_Speaker[*it].getScore(1) << ",";
	}
	ofs << endl;
	cout << "保存成功\n";
	isFileEmpty = false;
	ofs.close();
}

void SpeechManager::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		isFileEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		isFileEmpty = true;
		ifs.close();
		return;
	}

	isFileEmpty = false;
	ifs.putback(ch);

	string data;
	int index = 0;

	while (ifs >> data)
	{
		vector<string> v;
		int start = 0;
		int pos = -1;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}

			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}

		m_Record.insert(make_pair(index, v));
		index++;

	}

	ifs.close();//这句代码没有会怎么样？？？？？
}

void SpeechManager::showRecord()
{
	if (isFileEmpty)
	{
		cout << "没有比赛记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->m_Record.size(); ++i)
	{
		cout << "------------------------------------\n";
		cout << "第" << i + 1 << "届" << endl
			<< "冠军的编号：" << this->m_Record[i][0]
			<< " 得分：" << this->m_Record[i][1] << endl;
		cout << "亚军的编号：" << this->m_Record[i][2]
			<< " 得分：" << this->m_Record[i][3] << endl;
		cout << "季军的编号：" << this->m_Record[i][4]
			<< " 得分：" << this->m_Record[i][5] << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "请确认是否清空？" << endl;
	cout << "1、确认\n2、取消" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->InitSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::startSpeech()
{
	speechDraw();

	speechContest();

	showScore();

	show_Menu();

	Index++;

	speechDraw();

	speechContest();

	showScore();

	saveSpeech();

	system("pause");
	system("cls");

	InitSpeech();

	createSpeaker();

	loadRecord();
}

void SpeechManager::exit()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	std::exit(0);
}

void SpeechManager::error()
{
	cout << "输入错误，请重新输入!" << endl;
	system("pause");
	system("cls");
}