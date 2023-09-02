#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

void menu()
{
	printf("\t\t\t     *****************学生管理系统**************\n");
	printf("\t\t\t     *          1、输出所有学生信息            *\n");
	printf("\t\t\t     *          2、按学号或姓名查询学生信息    *\n");
	printf("\t\t\t     *          3、修改学生信息                *\n");
	printf("\t\t\t     *          4、添加一个学生信息            *\n");
	printf("\t\t\t     *          5、删除一个学生信息            *\n");
	printf("\t\t\t     *          0、退出系统                    *\n");
	printf("\t\t\t     *******************************************\n");
}

void LoadStudent(SeqList* psl)//从"student.txt"文件中将信息读取处理
{
	FILE* pfread = fopen("student.txt", "rb");
	if (pfread == NULL)
	{
		printf("LoadStudent::%s", strerror(errno));
		return;
	}

	student temp;
	while (fread(&temp, sizeof(student), 1, pfread));//加了个;导致数据只加载了一个!!!!!!!!
	while (fread(&temp, sizeof(student), 1, pfread))
	{
		CheckCapacity(psl);
		psl->data[psl->size] = temp;
		psl->size++;
	}

	fclose(pfread);
	pfread = NULL;
}

void InItSeqList(SeqList* psl)//初始化
{
	psl->data = (student*)malloc(STARTCAP * sizeof(student));

	if (psl == NULL)
	{
		return;
	}
	psl->size = 0;
	psl->capacity = STARTCAP;

	LoadStudent(psl);//加载student.txt中的文件到psl中

}

void CheckCapacity(SeqList* psl)//检查容量是否足够，不够realloc更多空间
{
	if (psl->size == psl->capacity)
	{
		//student* temp = (student*)realloc(psl->data, (psl->capacity + 1) * sizeof(student));
		student* temp = realloc(psl->data, (psl->capacity + 1) * sizeof(student));
		if (temp == NULL)
		{
			printf("CheckCapacity::%s", strerror(errno));
			return;
		}

		psl->data = temp;
		psl->capacity++;
		printf("扩容成功\n");
	}
}

void saveStudent(SeqList* psl)//保存学生信息到student.txt文件
{
	FILE* pfwrite = fopen("student.txt", "wb");
	if (fwrite == NULL)
	{
		printf("saveStudent::%s", strerror(errno));//判断错误原因
		return;
	}

	int i = 0;
	for (; i < psl->size; ++i)
	{
		//fwrite(&psl->data[i], sizeof(student), 1, pfwrite);
		fwrite(&(psl->data[i]), sizeof(student), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}


void print(SeqList* psl)//打印所有student信息
{
	if (psl->size == 0)
	{
		printf("无学生信息\n");
		return;
	}
	//system("chcp 65001");
	int i = 0;
	printf("学号\t\t姓名\t性别\t班级\t\t联系电话\t\tC语言成绩\n");
	for (; i < psl->size; ++i)
	{
		printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
			psl->data[i].m_Num,
			psl->data[i].m_Name,
			psl->data[i].m_Sex,
			psl->data[i].m_ClassName,
			psl->data[i].m_Tele,
			psl->data[i].m_Score);
	}

}

int findStudent_Num(SeqList* psl, char Num[NUMMAX])//按学号查找，返回位置i
{
	int i = 0;
	for (; i < psl->size; ++i)
	{
		if (!strcmp(psl->data[i].m_Num, Num))
		{
			return i;
		}
	}

	return -1;//没有查到返回-1
}

int findStudent_Name(SeqList* psl, char Name[NAMEMAX])//按姓名查找，返回位置i
{
	int i = 0;
	for (; i < psl->size; ++i)
	{
		if (!strcmp(psl->data[i].m_Name, Name))
		{
			return i;
		}
	}

	return -1;//没有查到返回-1
}

void findStudent(SeqList* psl)//按学号或姓名查询学生信息
{
	while (1)
	{
		int select;
		printf("请输入你的查询方式：\n");
		printf("1、按学号查询\n2、按姓名查询\n");
		scanf("%d", &select);
		int ret = 0;

		if (select == 1)//按学号查询
		{
			char Num[NUMMAX];
			printf("请输入要查找学生的学号：");
			scanf("%s", Num);
			ret = findStudent_Num(psl, Num);
		}
		else if (select == 2)//按姓名查询
		{
			char Name[NAMEMAX];
			printf("请输入要查找学生的姓名：");
			scanf("%s", Name);
			ret = findStudent_Name(psl, Name);
		}
		else
		{
			printf("输入错误，请重新输入\n");
			continue;
		}

		if (ret == -1)
		{
			printf("查无此人\n");
		}
		else
		{
			printf("学号\t\t姓名\t性别\t班级\t\t联系电话\t\tC语言成绩\n");
			printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
				psl->data[ret].m_Num,
				psl->data[ret].m_Name,
				psl->data[ret].m_Sex,
				psl->data[ret].m_ClassName,
				psl->data[ret].m_Tele,
				psl->data[ret].m_Score);
		}

		printf("是否继续查询：\n");
		printf("1、继续查询\n2、结束查询\n");
		scanf("%d", &select);

		if (select == 2)
		{
			break;
		}
	}
	
}

void modifyStudent(SeqList* psl)//修改学生信息
{
	while (1)
	{
		int select;
		printf("请输入你的查询要修改学生方式：\n");
		printf("1、按学号查询\n2、按姓名查询\n");
		scanf("%d", &select);
		int ret = 0;

		if (select == 1)//按学号查询
		{
			char Num[NUMMAX];
			printf("请输入要修改学生的学号：");
			scanf("%s", Num);
			ret = findStudent_Num(psl, Num);
		}
		else if (select == 2)//按姓名查询
		{
			char Name[NAMEMAX];
			printf("请输入要修改学生的姓名：");
			scanf("%s", Name);
			ret = findStudent_Name(psl, Name);
		}
		else
		{
			printf("输入错误，请重新输入\n");
			continue;
		}

		if (ret == -1)
		{
			printf("查无此人\n");
		}
		else
		{
			printf("学号\t\t姓名\t性别\t班级\t\t联系电话\t\tC语言成绩\n");
			printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
				psl->data[ret].m_Num,
				psl->data[ret].m_Name,
				psl->data[ret].m_Sex,
				psl->data[ret].m_ClassName,
				psl->data[ret].m_Tele,
				psl->data[ret].m_Score);
		}

		int t = 0;
		printf("是否修改此人：\n");
		printf("1、修改此人\n2、取消修改\n");
		scanf("%d", &t);
		if (t == 1)//修改此人
		{
			printf("请输入修改后学生的学号：");
			scanf("%s", psl->data[psl->size].m_Num);
			printf("请输入修改后学生的姓名：");
			scanf("%s", psl->data[psl->size].m_Name);
			printf("请输入修改后学生的性别：");
			scanf("%s", psl->data[psl->size].m_Sex);
			printf("请输入修改后学生的班级姓名：");
			scanf("%s", psl->data[psl->size].m_ClassName);
			printf("请输入修改后学生的联系电话：");
			scanf("%s", psl->data[psl->size].m_Tele);
			printf("请输入修改后学生的C语言成绩：");
			scanf("%d", &psl->data[psl->size].m_Score);
			printf("修改成功\n");
		}
		else
		{
			printf("已取消修改");
		}

		printf("是否继续修改：\n");
		printf("1、继续修改\n2、结束修改\n");
		scanf("%d", &select);

		if (select == 2)
		{
			break;
		}
	}
}

void addStudent(SeqList* psl)//添加学生信息
{
	CheckCapacity(psl);

	printf("请输入要添加学生的学号：");
	scanf("%s", psl->data[psl->size].m_Num);
	printf("请输入要添加学生的姓名：");
	scanf("%s", psl->data[psl->size].m_Name);
	printf("请输入要添加学生的性别：");
	scanf("%s", psl->data[psl->size].m_Sex);
	printf("请输入要添加学生的班级姓名：");
	scanf("%s", psl->data[psl->size].m_ClassName);
	printf("请输入要添加学生的联系电话：");
	scanf("%s", psl->data[psl->size].m_Tele);
	printf("请输入要添加学生的C语言成绩：");
	scanf("%d", &psl->data[psl->size].m_Score);

	psl->size++;
	saveStudent(psl);
	printf("添加成功\n");
}

void deleteStudent(SeqList* psl)//删除学生信息
{
	while (1)
	{
		int select;
		printf("请输入你的查询要删除学生方式：\n");
		printf("1、按学号查询\n2、按姓名查询\n");
		scanf("%d", &select);
		int ret = 0;

		if (select == 1)//按学号查询
		{
			char Num[NUMMAX];
			printf("请输入要删除学生的学号：");
			scanf("%s", Num);
			ret = findStudent_Num(psl, Num);
		}
		else if (select == 2)//按姓名查询
		{
			char Name[NAMEMAX];
			printf("请输入要删除学生的姓名：");
			scanf("%s", Name);
			ret = findStudent_Name(psl, Name);
		}
		else
		{
			printf("输入错误，请重新输入\n");
			continue;
		}

		if (ret == -1)
		{
			printf("查无此人\n");
		}
		else
		{
			printf("学号\t\t姓名\t性别\t班级\t\t联系电话\t\tC语言成绩\n");
			printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
				psl->data[ret].m_Num,
				psl->data[ret].m_Name,
				psl->data[ret].m_Sex,
				psl->data[ret].m_ClassName,
				psl->data[ret].m_Tele,
				psl->data[ret].m_Score);
		}

		int t = 0;
		printf("是否删除此人：\n");
		printf("1、删除此人\n2、取消删除\n");
		scanf("%d", &t);
		if (t == 1)//删除此人
		{
			int j = ret;
			for (; j < psl->size - 1; ++j)
			{
				psl->data[j] = psl->data[j + 1];
			}

			psl->size--;
			printf("删除成功\n");

			
		}
		else
		{
			printf("已取消删除");
		}

		printf("是否继续删除：\n");
		printf("1、继续删除\n2、结束删除\n");
		scanf("%d", &select);

		if (select == 2)
		{
			break;
		}
	}
}

void DestroyContact(SeqList* psl)//清空全部（销毁student.txt）
{
	free(psl);
	psl = NULL;
	printf("已清空所有学生信息\n");
}