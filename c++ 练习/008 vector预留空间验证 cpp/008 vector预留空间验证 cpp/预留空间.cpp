#include <iostream>
#include <vector>

using namespace std;


void printVector(vector<int> v)
{
	int j = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (j < 10)
		{
			cout << *it << " ";
			j++;
		}
		else
		{
			cout << "\n";
			j = 0;
		}
	}
}

void test()
{
	vector<int> v;
	int* p = NULL;
	int num = 0;
	//v.reserve(10000);
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		//printVector(v);
		if (p != &v[0])//Ϊʲô��������p!=v.begin()?????
		{
			p = &v[0];
			num++;
		}
	}
	
	cout << num << endl;//�������reserveֱ�ӿ��٣���ôϵͳ��Ҫ������24���ڴ�

}


int main()
{
	test();
	return 0;
}