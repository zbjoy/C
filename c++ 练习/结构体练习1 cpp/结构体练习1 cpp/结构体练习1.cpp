#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

typedef struct Student
{
	string name;
	int score;
}student;
typedef struct Teacher
{
	string name;
	student s[5];
}teacher;
int main() {
	teacher t[3];//teacher t[3] = { 0 };�����ʼ����������21�д����ڵ���ʱ��������
	for (int i = 0; i < 3; i++)
	{
		cout << "�������" << i + 1 << "λ��ʦ��������";
		cin >> t[i].name;
		//0x00007FFEDE5E7A41 (ucrtbased.dll)��(λ�� �ṹ����ϰ1 cpp.exe ��)�������쳣: 0xC0000005: ��ȡλ�� 0x0000000000000000 ʱ�������ʳ�ͻ��
		cout << "�������" << i + 1 << "λ��ʦ������ѧ����Ϣ��\n";
		for (int j = 0; j < 5; j++)
		{
			cout << "�������" << j + 1 << "λѧ����������";
			cin >> t[i].s[j].name;
			//scanf("%s", &(t[i].s[j].name))������scanf��ȡstring���͵��ַ���;
			//cin<<t[i].s[j]�ᱨ��û����֮��Ӧ�ġ�<<��  ???
			//�ѽ��   Ӧ����cin<<t[i].s[j].name�Ŷ�
			cout << "�������" << j + 1 << "λѧ���ĳɼ���";
			cin >> t[i].s[j].score;
		}
		cout << "\n";
	}
	system("pause");
	system("cls");
		for (int i = 0; i < 3; i++)
		{
			cout << "������ʦΪ" << t[i].name << "\n";
			for (int j = 0; j < 5; j++)
			{
				cout << "��" << j +1<< "λѧ��������" << t[i].s[j].name << "\n";
				cout << "��" << j+1 << "λѧ���ɼ���" << t[i].s[j].score << "\n";
			}
			cout << "\n";
		}
	return 0;
}