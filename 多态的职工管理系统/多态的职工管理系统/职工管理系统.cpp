#include "workManager.h"



int main()
{
	int choice=0;
	WorkerManager wm;
	//wm.InIt_Emp();
	while (true)
	{
		system("cls");
		wm.Show_Menu();
		cout << "���������ѡ��";
		cin >> choice;
		switch (choice)
		{ 
		//�˳��������
		case 0:
			wm.exitSystem();
			break;
		//����ְ����Ϣ
		case 1:
			wm.Add_Emp();
			break;
		//��ʾְ����Ϣ
		case 2:
			wm.Show_Emp();
			break;
		//ɾ��ְ����Ϣ
		case 3:
			wm.Del_Emp();
			break;
		//�޸�ְ����Ϣ
		case 4:
			wm.Mod_Emp();
			break;
		//����ְ����Ϣ
		case 5:
			wm.Find_Emp();
			break;
		//���ձ������
		case 6:
			wm.Sort_Emp();
			break;
		//��������ĵ�
		case 7:
			wm.Clean_File();
			break;
		default:
			break;
		}
		system("pause");
	}

	return 0;
}