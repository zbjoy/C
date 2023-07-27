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
		cout << "���ݳɹ�\n";
		p->capacity++;
	}
}
void LoadContact(Contact* p)
{
	FILE* pfread = fopen("����һͨ", "rb");
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
	cout << "|  1.�����ϵ��      2.������ϵ�� |\n";
	cout << "|  3.������ϵ��      4.ɾ����ϵ�� |\n";
	cout << "|  5.��ʾ��ϵ��      0.�˳�ͨѶ¼ |\n";
}
void ContactInIt(Contact* p)
{
	p->data = (People*)malloc(3*sizeof(People));//�ǲ�������ʹ��new���ٽṹ������Ŀռ䣿��
	p->size = 0;
	p->capacity = 3;
	LoadContact(p);
}
void AddContact(struct Contact* p)
{
	CheckCapacity(p);
	cout << "��������Ҫ��ӵ���ϵ�˵�������";
	cin >> p->data[p->size].name;
	cout << "��������Ҫ��ӵ���ϵ�˵����䣺";
	cin >> p->data[p->size].age;
	cout << "��������Ҫ��ӵ���ϵ�˵��Ա�";
	cin >> p->data[p->size].gender;
	cout << "��������Ҫ��ӵ���ϵ�˵ĵ绰��";
	cin >> p->data[p->size].tele;
	cout << "��������Ҫ��ӵ���ϵ�˵ĵ�ַ��";
	cin >> p->data[p->size].addr;
	p->size++;
	cout << "��ӳɹ�\n";
}
void ShowContact(Contact* p)
{
	cout << "���\t����\t����\t�Ա�\t�绰\t\t��ַ\n";
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
	cout << "���޴���";
	return -1;
}
void FindContact(Contact* p)
{
	cout << "��������Ҫ���ҵ��˵�������";
	string name;
	cin >> name;
	int pos = FindPos(p, name);
	if (pos != -1)
	{
		cout << "���\t����\t����\t�Ա�\t�绰\t\t��ַ\n";
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
	cout << "��������Ҫ���ҵ��˵�������";
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
		cout << "��ɾ������\n";
	}
	
}
void SaveContact(Contact* p)
{
	FILE* pfwrite = fopen("����һͨ", "wb");
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
	cout << "�����ɹ�\n";
}