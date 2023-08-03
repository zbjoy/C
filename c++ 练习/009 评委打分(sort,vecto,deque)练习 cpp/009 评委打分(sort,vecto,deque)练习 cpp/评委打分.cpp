#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include <deque>
#include <ctime>

using namespace std;

class Person
{
public:

	Person(string name);
	Person(string name,int score);

	string m_Name;
	int m_Score;
};

Person::Person(string name, int score)
{
	m_Name = name;
	m_Score = score;
}

Person::Person(string name)
{
	m_Name = name;
}

void tellPerson(Person& p,int score)
{
	p.m_Score = score;
}

void showkankan(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

void dafeng(Person& p)
{
	deque<int> d;
	cout << "ѡ�֣�" << p.m_Name << "��\n";
	for (int i = 0; i < 10; i++)
	{
		//int temp = 0;
		//cout << "��ί" << i + 1 << "��֣�";
		//cin >> temp;
		//d.push_back(temp);//ֱ�ӽ���
		int temp = rand() % 41 + 60;
		d.push_back(temp);
	}
	//cout << "����ǰ:\n";
	//showkankan(d);
	sort(d.begin(), d.end());
	//cout << "�����:\n";
	//showkankan(d);
	d.pop_back();
	d.pop_front();
	//cout << "ɾ����:\n";
	showkankan(d);
	int sum = 0;
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		sum += *it;
	}
	int score = sum / d.size();
	tellPerson(p, score);
}


ostream& operator<<(ostream& print, Person& p)
{
	cout << "ѡ�֣�" << p.m_Name << "\t" << "�÷֣�" << p.m_Score << endl;
	return print;
}

void printpinfen(Person& p)
{
	cout << p ;
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Person> v;
	Person p1("����");
	Person p2("����");
	//Person p3("����");
	//Person p4("����");
	//Person p5("����");
	dafeng(p1);
	dafeng(p2);
	printpinfen(p1);
	printpinfen(p2);
	return 0;
}