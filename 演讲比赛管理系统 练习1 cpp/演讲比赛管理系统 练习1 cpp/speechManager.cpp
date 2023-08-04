#include "speechManager.h"



//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

	this->loadRecord();
}

//菜单函数
void SpeechManager::show_Menu()
{
	cout << "************************************\n";
	cout << "******    欢迎参加演讲比赛    ******\n";
	cout << "******     1.开始演讲比赛     ******\n";
	cout << "******     2.查看往届记录     ******\n";
	cout << "******     3.清空比赛记录     ******\n";
	cout << "******     0.退出比赛程序     ******\n";
	cout << "************************************\n";
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用\n";
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;

	//将记录的容器也清空
	m_Record.clear();
}

//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，并且放入到v1容器中
		this->v1.push_back(i + 1001);

		//选手编号以及对应选手，放到map容器中
		this->m_Speaker.insert(pair<int, Speaker>(v1[i], sp));

	}
}

//开始比赛
void SpeechManager::startSpeech()
{
	//开始第一轮比赛

	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();
	//第二轮开始比赛
	m_Index++;
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示最终结果
	this->showScore();
	//4、保存分数到文件中
	this->saveRecord();

	//重置比赛，获取记录
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

	this->loadRecord();

	cout << "本届比赛完毕!" << endl;
	system("pause");
}

//抽签
void SpeechManager::speechDraw()
{
	//cout << "第" << m_Index << "轮比赛选手正在抽签" << endl;
	cout << "第<<" << m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "-------------------------------" << endl;
	Sleep(2000);
	cout << "抽签后演讲顺序如下：" << endl;
	if (m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void SpeechManager::speechContest()
{
	//准备临时容器，存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0;//记录人员个数

	cout << "------------第<<" << this->m_Index << ">>轮的比赛正式开始------------\n";
	vector<int> v_Src;//比赛选手容器
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << "\n";
		sort(d.begin(), d.end(), greater<double>());//排序，不这样就默认用less<T>也应该可以
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
		double avg = sum / (double)d.size();//平均分

		//打印平均分
		//cout << "选手编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 平均分：" << avg<<endl;

		//将平均分放入map容器
		m_Speaker[*it].m_Score[m_Index - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));
		//每六人取出前三名
		if (num%6==0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second
					<< " 姓名：" << m_Speaker[it->second].m_Name
					<< " 成绩：" << m_Speaker[it->second].m_Score[m_Index - 1]
					<< endl;
			}
			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			cout << endl;
			groupScore.clear();//小组容器清空
		}
	}
	cout << "------------第<<" << this->m_Index << ">>轮的比赛完毕!------------\n";
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "------------第<<" << this->m_Index << ">>轮晋级选手如下------------\n";
	vector<int> v;
	if (m_Index == 1)
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
			<< " 姓名：" << m_Speaker[*it].m_Name
			<< " 成绩：" << m_Speaker[*it].m_Score[m_Index-1]
			<< endl;
	}
	cout << endl;

	system("pause");
}

//保存记录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将每个选手的数据写入文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭
	ofs.close();
	cout << "记录已经保存\n";

	//更改文件状态
	fileIsEmpty = false;
}

//读取记录
void SpeechManager::loadRecord()
{
	//文件不存在的情况
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在\n";
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件清空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空\n";
		fileIsEmpty = true;
		ifs.close();
	}

	//文件不为空
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index=0;
	while (ifs >> data)
	{
		vector<string> v;//存放六个string的字符串
		//cout << data<<endl;
		int pos = -1;//查","的位置
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	
}

//显示往届得分
void SpeechManager::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "文件为空或不存在!\n";
		return;
	}
	for (int i = 0; i < m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届"
			<< "冠军编号：" << m_Record[i][0]
			<< "得分：" << m_Record[i][1]
			<< endl;
		cout << "第" << i + 1 << "届"
			<< "亚军编号：" << m_Record[i][2]
			<< "得分：" << m_Record[i][3]
			<< endl;
		cout << "第" << i + 1 << "届"
			<< "季军编号：" << m_Record[i][4]
			<< "得分：" << m_Record[i][5]
			<< endl;
		cout << endl;
	}
	system("pause");
}

//析构函数
SpeechManager::~SpeechManager()
{

}