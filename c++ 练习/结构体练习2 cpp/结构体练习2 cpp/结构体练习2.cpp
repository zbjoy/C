#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name;
	int age;
	char sex[2];//汉字需要两个字节储存
};
int sort_by_age(void* a, void* b)
{
	return ((student*)a)->age-((student*)b)->age;
}
void swap(char* e1, char* e2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *(e1 + i);
		*(e1 + i) = *(e2 + i);
		*(e2 + i) = tmp;
	}
}
void my_sort(void* p,int sz,int width, int (*cmp)(void* a, void* b))
{
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)p + j * width, (char*) p + (j + 1) * width)>0)
			{
				swap((char*)p + j * width, (char*)p + (j + 1) * width, width);
			}
		}
	}
}
int main()
{
	student stu[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i+1 << "位的姓名：";
		cin >> stu[i].name;
		cout << "请输入第" << i+1 << "位的年龄：";
		cin >> stu[i].age;
		cout << "请输入第" << i+1 << "位的性别：";
		cin >> stu[i].sex;
		cout << "\n";
	}
	my_sort(stu, sizeof(stu) / sizeof(stu[0]), sizeof(student), sort_by_age);
	for (int i = 0; i < 3; i++)
	{
		cout << "第" << i+1 << "位的姓名：";
		cout << stu[i].name<<"\n";
		cout << "第" << i+1 << "位的年龄：";
		cout << stu[i].age<<"\n";
		cout << "第" << i+1 << "位的性别：";
		cout << stu[i].sex<<"\n";
	}
	return 0;
}