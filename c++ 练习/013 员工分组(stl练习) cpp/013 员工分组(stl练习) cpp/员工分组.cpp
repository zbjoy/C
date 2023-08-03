#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>


using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:

	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

void printVector(vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Salary << endl;
	}
}

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it ++ )
	{
		int deptId = rand() % 3;
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGourp(multimap<int,Worker>& m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count=m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------\n";
	index = 0;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	cout << "美术部门：" << endl;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------\n";
	index = 0;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	cout << "研发部门：" << endl;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}

}

int main()
{
	srand((unsigned int)time(NULL));
	//1.创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);
	printVector(vWorker);
	cout << "\n";
	//2.员工分组
	multimap<int, Worker> mWorker;
	setGroup(vWorker,mWorker);
	showWorkerByGourp(mWorker);
	return 0;
}