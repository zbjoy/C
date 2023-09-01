#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void menu()
{
	printf("\t\t\t     **********学生管理系统**********\n");
	printf("\t\t\t     *      1、输出所有学生信息     *\n");
	printf("\t\t\t     *      2、按学号查询学生信息   *\n");
	printf("\t\t\t     *      3、修改学生信息         *\n");
	printf("\t\t\t     *      4、添加一个学生信息     *\n");
	printf("\t\t\t     *      5、删除一个学生信息     *\n");
	printf("\t\t\t     *      0、退出系统             *\n");
	printf("\t\t\t     ********************************\n");
}


static void CheckCapacity(SeqList* list)
{
	if (list->capacity <= list->len)
	{
		datatype* tmp = (datatype*)realloc(list->data, (list->capacity + 1) * sizeof(datatype));
		if (tmp == NULL)
		{
			printf("扩容失败！\n");
			return;
		}
		list->data = tmp;
		list->capacity++;
		printf("扩容成功!\n");
	}

}

void LoadStudent(SeqList* list)
{
	FILE* pfread = fopen("student.txt", "rb");

	datatype tmp;
	while (fread(&tmp, sizeof(datatype),1, pfread))
	{
		CheckCapacity(list);
		list->data[list->len] = tmp;
		list->len++;
	}

	fclose(pfread);
}

void Save(SeqList* list)
{
	FILE* pfwrite;
	pfwrite = fopen("student.txt", "wb");
	int i = 0;
	for (; i < list->len; i++)
	{
		fwrite(&list->data[i], sizeof(datatype),1, pfwrite);
	}
	fclose(pfwrite);
}


void initSeqList(SeqList* list)
{
	//为什么一添加学生就会退出
	list->data = (datatype*)malloc(MAXSIZE*sizeof(datatype));
	
	list->len = 0;
	list->capacity = MAXSIZE;

	LoadStudent(list);
}

void printAllStudent(SeqList* list)
{
	int i = 0;
	int j = 0;
	printf("学号\t\t姓名\t班级\t成绩\n");
	for (; i < list->len; i++)
	{
		printf("%s\t\t%s\t%s\t%d\n",
			list->data[i].num,
			list->data[i].name,
			list->data[i].classname,
			list->data[i].score);

	}
}

static int findNum(SeqList* list,char v[NUMMAX])
{
	int i = 0;
	for (; i < list->len; ++i)
	{
		if (!strcmp(v, list->data[i].num))
		{
			return i;
		}
	}
	return -1;
}

void findStudent_Num(SeqList* list)
{
	char val[NUMMAX];
	printf("请输入查找人的学号：");
	scanf("%s", val);
	int ret = findNum(list, val);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	printf("学号\t\t姓名\t班级\t成绩\n");
	printf("%s\t\t%s\t%s\t%d\n",
		list->data[ret].num,
		list->data[ret].name,
		list->data[ret].classname,
		list->data[ret].score);
	
}

void xiugai_Num(SeqList* list)
{
	char val[NUMMAX];
	printf("请输入要修改人的学号：");
	scanf("%s", val);
	int ret = findNum(list, val);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	printf("学号\t\t姓名\t班级\t成绩\n");
	printf("%s\t\t%s\t%s\t%d\n",
		list->data[ret].num,
		list->data[ret].name,
		list->data[ret].classname,
		list->data[ret].score);

	int select;
	printf("是否修改此人\n");
	printf("1、修改\n2、取消\n");
	scanf("%d", &select);
	if (select == 1)
	{
		printf("请输入要修改学生的学号为：");
		scanf("%s", list->data[ret].num);
		printf("请输入要修改学生的姓名为：");
		scanf("%s", list->data[ret].name);
		printf("请输入要修改学生的班级姓名为：");
		scanf("%s", list->data[ret].classname);
		printf("请输入要修改学生的成绩为：");
		scanf("%d", &list->data[ret].score);
	}
	
	else
	{
		printf("已取消修改！\n");
	}
	return;
}

void addStudent(SeqList* list)
{
	//char num[NUMMAX];//学号
	//char name[NAMEMAX];//姓名
	//char classname[CLASSNAMEMAX];//班级姓名
	//int score;//成绩
	CheckCapacity(list);
	printf("请输入要添加学生的学号：");
	scanf("%s", list->data[list->len].num);
	printf("请输入要添加学生的姓名：");
	scanf("%s", list->data[list->len].name);
	printf("请输入要添加学生的班级姓名：");
	scanf("%s", list->data[list->len].classname);
	printf("请输入要添加学生的成绩：");
	scanf("%d", &list->data[list->len].score);

	list->len++;

	Save(list);
	printf("添加成功！\n");
}

void deleteStudent(SeqList* list)
{
	char val[NUMMAX];
	printf("请输入要删除人的学号：");
	scanf("%s", val);
	int ret = findNum(list, val);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	printf("学号\t\t姓名\t班级\t成绩\n");
	printf("%s\t\t%s\t%s\t%d\n",
		list->data[ret].num,
		list->data[ret].name,
		list->data[ret].classname,
		list->data[ret].score);

	int select;
	printf("是否删除此人\n");
	printf("1、删除\n2、取消\n");
	scanf("%d", &select);

	if (select == 1)
	{
		int i = ret;
		for (; i < list->len - 1; i++)
		{
			list->data[i] = list->data[i + 1];
		}
		list->len--;
	}
	else
	{
		printf("删除已取消\n");
		return;
	}
}