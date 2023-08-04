#include "speechManager.h"



//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();

	this->loadRecord();
}

//�˵�����
void SpeechManager::show_Menu()
{
	cout << "************************************\n";
	cout << "******    ��ӭ�μ��ݽ�����    ******\n";
	cout << "******     1.��ʼ�ݽ�����     ******\n";
	cout << "******     2.�鿴�����¼     ******\n";
	cout << "******     3.��ձ�����¼     ******\n";
	cout << "******     0.�˳���������     ******\n";
	cout << "************************************\n";
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��\n";
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;

	//����¼������Ҳ���
	m_Record.clear();
}

//����12��ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ҷ��뵽v1������
		this->v1.push_back(i + 1001);

		//ѡ�ֱ���Լ���Ӧѡ�֣��ŵ�map������
		this->m_Speaker.insert(pair<int, Speaker>(v1[i], sp));

	}
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��ʼ��һ�ֱ���

	//1����ǩ
	this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ�������
	this->showScore();
	//�ڶ��ֿ�ʼ����
	m_Index++;
	//1����ǩ
	this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ���ս��
	this->showScore();
	//4������������ļ���
	this->saveRecord();

	//���ñ�������ȡ��¼
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();

	this->loadRecord();

	cout << "����������!" << endl;
	system("pause");
}

//��ǩ
void SpeechManager::speechDraw()
{
	//cout << "��" << m_Index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "��<<" << m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------------" << endl;
	Sleep(2000);
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
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

//����
void SpeechManager::speechContest()
{
	//׼����ʱ���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	int num = 0;//��¼��Ա����

	cout << "------------��<<" << this->m_Index << ">>�ֵı�����ʽ��ʼ------------\n";
	vector<int> v_Src;//����ѡ������
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << "\n";
		sort(d.begin(), d.end(), greater<double>());//���򣬲�������Ĭ����less<T>ҲӦ�ÿ���
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);//�ܷ�
		double avg = sum / (double)d.size();//ƽ����

		//��ӡƽ����
		//cout << "ѡ�ֱ�ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " ƽ���֣�" << avg<<endl;

		//��ƽ���ַ���map����
		m_Speaker[*it].m_Score[m_Index - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));
		//ÿ����ȡ��ǰ����
		if (num%6==0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second
					<< " ������" << m_Speaker[it->second].m_Name
					<< " �ɼ���" << m_Speaker[it->second].m_Score[m_Index - 1]
					<< endl;
			}
			//ȡ��ǰ����
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
			groupScore.clear();//С���������
		}
	}
	cout << "------------��<<" << this->m_Index << ">>�ֵı������!------------\n";
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "------------��<<" << this->m_Index << ">>�ֽ���ѡ������------------\n";
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
		cout << "ѡ�ֱ�ţ�" << *it
			<< " ������" << m_Speaker[*it].m_Name
			<< " �ɼ���" << m_Speaker[*it].m_Score[m_Index-1]
			<< endl;
	}
	cout << endl;

	system("pause");
}

//�����¼
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	//��ÿ��ѡ�ֵ�����д���ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر�
	ofs.close();
	cout << "��¼�Ѿ�����\n";

	//�����ļ�״̬
	fileIsEmpty = false;
}

//��ȡ��¼
void SpeechManager::loadRecord()
{
	//�ļ������ڵ����
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������\n";
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���յ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��\n";
		fileIsEmpty = true;
		ifs.close();
	}

	//�ļ���Ϊ��
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index=0;
	while (ifs >> data)
	{
		vector<string> v;//�������string���ַ���
		//cout << data<<endl;
		int pos = -1;//��","��λ��
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//û���ҵ�
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

//��ʾ����÷�
void SpeechManager::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!\n";
		return;
	}
	for (int i = 0; i < m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "��"
			<< "�ھ���ţ�" << m_Record[i][0]
			<< "�÷֣�" << m_Record[i][1]
			<< endl;
		cout << "��" << i + 1 << "��"
			<< "�Ǿ���ţ�" << m_Record[i][2]
			<< "�÷֣�" << m_Record[i][3]
			<< endl;
		cout << "��" << i + 1 << "��"
			<< "������ţ�" << m_Record[i][4]
			<< "�÷֣�" << m_Record[i][5]
			<< endl;
		cout << endl;
	}
	system("pause");
}

//��������
SpeechManager::~SpeechManager()
{

}