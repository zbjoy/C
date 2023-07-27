#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"


void CheckCapacity(Contact* p)
{
	if (p->size == p->capacity)
	{
		People* tmp =(People*)realloc(p->data, (p->size + 1) * sizeof(People));
		if (tmp == NULL)
		{
			return;
		}
		p->data = tmp;
		cout << "扩容成功\n";
		p->capacity++;
	}
}
void LoadContact(Contact* p)
{
	FILE* pfread = fopen("乱起一通", "rb");
	if (pfread == NULL)
	{
		return;
	}
	People tmp;
	while (fread(&tmp, sizeof(People), 1, pfread))
	{
		CheckCapacity(p);
		p->data[p->size] = tmp;
		p->size++;
	}
	fclose(pfread);
	pfread = NULL;
}
void menu()
{
	cout << "___________________________________\n";
	cout << "|  1.添加联系人      2.查找联系人 |\n";
	cout << "|  3.保留联系人      4.删除联系人 |\n";
	cout << "|  5.显示联系人      0.退出通讯录 |\n";
}
void ContactInIt(Contact* p)
{
	p->data = (People*)malloc(3*sizeof(People));//是不是这样使用new开辟结构体数组的空间？？
	p->size = 0;
	p->capacity = 3;
	LoadContact(p);
}
void AddContact(struct Contact* p)
{
	CheckCapacity(p);
	cout << "请输入您要添加的联系人的姓名：";
	cin >> p->data[p->size].name;
	cout << "请输入您要添加的联系人的年龄：";
	cin >> p->data[p->size].age;
	cout << "请输入您要添加的联系人的性别：";
	cin >> p->data[p->size].gender;
	cout << "请输入您要添加的联系人的电话：";
	cin >> p->data[p->size].tele;
	cout << "请输入您要添加的联系人的地址：";
	cin >> p->data[p->size].addr;
	p->size++;
	cout << "添加成功\n";
}
void ShowContact(Contact* p)
{
	cout << "序号\t姓名\t年龄\t性别\t电话\t\t地址\n";
	for (int i = 0; i < p->size; i++)
	{
		cout<<i+1<<"\t"
			<< p->data[i].name << "\t"
			<< p->data[i].age << "\t"
			<< p->data[i].gender << "\t"
			<< p->data[i].tele << "\t"
			<< p->data[i].addr << "\n";
	}
}
int FindPos(struct Contact* p, string name)
{
	for (int i = 0; i < p->size; i++)
	{
		if (name == p->data[i].name)
		{
			return i;
		}
	}
	cout << "查无此人";
	return -1;
}
void FindContact(Contact* p)
{
	cout << "请输入您要查找的人的姓名：";
	string name;
	cin >> name;
	int pos = FindPos(p, name);
	if (pos != -1)
	{
		cout << "序号\t姓名\t年龄\t性别\t电话\t\t地址\n";
		cout << pos + 1 << "\t"
			<< p->data[pos].name << "\t"
			<< p->data[pos].age << "\t"
			<< p->data[pos].gender << "\t"
			<< p->data[pos].tele << "\t"
			<< p->data[pos].addr << "\n";
	}
}
void DelContact(Contact* p)
{
	cout << "请输入您要查找的人的姓名：";
	string name;
	cin >> name;
	int pos = FindPos(p, name);
	if (pos != -1)
	{
		for (int i = pos; i < p->size; i++)
		{
			p->data[i] = p->data[i + 1];
		}
		p->size--;
		cout << "已删除此人\n";
	}
	
}
void SaveContact(Contact* p)
{
	FILE* pfwrite = fopen("乱起一通", "wb");
	if (pfwrite == NULL)
	{
		return;
	}
	for (int i = 0; i < p->size; i++)
	{
		fwrite(&p->data[i], sizeof(People), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
	cout << "保留成功\n";
}