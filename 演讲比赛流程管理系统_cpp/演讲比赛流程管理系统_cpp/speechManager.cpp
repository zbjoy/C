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
	cout << "******    欢迎参加演讲比赛    ******\n";
	cout << "******     1.开始演讲比赛     ******\n";
	cout << "******     2.查看往届记录     ******\n";
	cout << "******     3.清空比赛记录     ******\n";
	cout << "******     0.退出比赛程序     ******\n";
	cout << "************************************\n";
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
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
		string name = "选手";
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
	cout << "----------第"<<this->m_Index<<"轮比赛开始------------" << endl;
	cout << endl;

	multimap<double, int, greater<double>> groupScore;//临时容器存放小组成绩

	int num = 0;//记录人员个数

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

		//cout << "编号:" << *it
		//	<< " 姓名:" << this->m_Speaker[*it].m_Name
		//	<< " 平均分:" << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));//key是得分,value是编号

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second 
					<< " 姓名：" << this->m_Speaker[it->second].m_Name 
					<< " 成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index - 1]
					<<endl;
			}

			//取走前三名，放入到下一轮容器中
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
	cout << "---------第" << this->m_Index << "轮比赛完毕！---------" << endl;;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "-----------第" << this->m_Index << "轮晋级选手信息如下：-----------------" << endl;

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
		cout << "选手编号：" << *it
			<< " 姓名：" << this->m_Speaker[*it].m_Name
			<< " 年龄：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
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

	cout << "记录已保存" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::startSpeaker()
{
	//第一轮

	//抽签
	this->speechDraw();

	//比赛
	this->speechContest();

	//显示晋级结果
	this->showScore();

	//第二轮
	this->m_Index++;

	//抽签
	this->speechDraw();

	//比赛
	this->speechContest();

	//显示最终结果
	this->showScore();
	
	//保存到文件中
	this->saveRecord();

	this->initSpeech();

	this->createSpeaeker();

	this->loadRecord();

	cout << "本届比赛结束！" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛正在抽签"<<endl;
	cout << "-----------------------------------------------" << endl;
	cout << "抽签后的演讲顺序如下：" << endl;

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
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
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

		vector<string> v;//存放6个string字符串

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
	//	cout << it->first << "冠军的得分：" << it->second[0] << " 分数：" << it->second[1] << endl;
	//}
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
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

		this->initSpeech();

		this->createSpeaeker();

		this->loadRecord();

		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}