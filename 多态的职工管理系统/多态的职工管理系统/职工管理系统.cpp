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
		cout << "请输入你的选择：";
		cin >> choice;
		switch (choice)
		{ 
		//退出管理程序
		case 0:
			wm.exitSystem();
			break;
		//增加职工信息
		case 1:
			wm.Add_Emp();
			break;
		//显示职工信息
		case 2:
			wm.Show_Emp();
			break;
		//删除职工信息
		case 3:
			wm.Del_Emp();
			break;
		//修改职工信息
		case 4:
			wm.Mod_Emp();
			break;
		//查找职工信息
		case 5:
			wm.Find_Emp();
			break;
		//按照编号排序
		case 6:
			wm.Sort_Emp();
			break;
		//清空所有文档
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