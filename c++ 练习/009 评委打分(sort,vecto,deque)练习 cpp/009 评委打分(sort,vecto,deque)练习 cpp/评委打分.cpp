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
	cout << "选手：" << p.m_Name << "：\n";
	for (int i = 0; i < 10; i++)
	{
		//int temp = 0;
		//cout << "评委" << i + 1 << "打分：";
		//cin >> temp;
		//d.push_back(temp);//直接交互
		int temp = rand() % 41 + 60;
		d.push_back(temp);
	}
	//cout << "排序前:\n";
	//showkankan(d);
	sort(d.begin(), d.end());
	//cout << "排序后:\n";
	//showkankan(d);
	d.pop_back();
	d.pop_front();
	//cout << "删除后:\n";
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
	cout << "选手：" << p.m_Name << "\t" << "得分：" << p.m_Score << endl;
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
	Person p1("张三");
	Person p2("李四");
	//Person p3("王五");
	//Person p4("老六");
	//Person p5("老七");
	dafeng(p1);
	dafeng(p2);
	printpinfen(p1);
	printpinfen(p2);
	return 0;
}