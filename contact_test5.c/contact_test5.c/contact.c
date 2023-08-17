#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void menu()
{
	printf("*************************************\n");
	printf("******1.add           2.del    ******\n");
	printf("******3.search        4.modify ******\n");
	printf("******5.show          6.sort   ******\n");
	printf("******7.capacity      8.save   ******\n");
	printf("******        0.exit           ******\n");
	printf("*************************************\n");
}

int findContact(Contact* con,char name[MAX_NAME])
{
	int i = 0;
	for (; i < con->size; ++i)
	{
		if (!strcmp(name,con->people[i].name))
		{
			return i;
		}
	}
	return -1;
}

void CheckCapacity(Contact* con)
{
	if (con->size == con->capacity)
	{
		PeoInFo* temp;
		temp = (PeoInFo*)realloc(con->people,sizeof(PeoInFo) * (con->capacity + 1));
		if (temp == NULL)
		{
			printf("CheckCapacity::%s", strerror(errno));
			return;
		}
		con->capacity ++;
		con->people = temp;
		printf("扩容成功\n");
	}
}

void LoadContact(Contact* con)
{
	PeoInFo temp = { 0 };
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s", strerror(errno));
		return;
	}
	while (fread(&temp, sizeof(PeoInFo), 1, pfRead))
	{
		CheckCapacity(con);
		con->people[con->size] = temp;
		con->size++;
	}
	fclose(pfRead);
	pfRead == NULL;
}

void InItContact(Contact* con)
{
	con->people = (PeoInFo*)malloc(sizeof(PeoInFo) * DEFAULT_SZ);
	if (con->people == NULL)
	{
		return 0;
	}
	con->capacity = DEFAULT_SZ;
	con->size = 0;
	LoadContact(con);
}

void addContact(Contact* con)
{
	CheckCapacity(con);
	printf("请输入要添加人的姓名：");
	scanf("%s", con->people[con->size].name);
	printf("请输入要添加人的年龄：");
	scanf("%d", &con->people[con->size].age);
	printf("请输入要添加人的性别：");
	scanf("%s", con->people[con->size].sex);
	printf("请输入要添加人的电话：");
	scanf("%s", con->people[con->size].tele);
	printf("请输入要添加人的地址：");
	scanf("%s", con->people[con->size].addr);
	con->size++;
	save(con);
}

void delContact(Contact* con)
{
	char name[MAX_NAME];
	printf("请输入要删除人的姓名：");
	scanf("%s", name);
	int ret = findContact(con, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("姓名\t年龄\t性别\t电话\t\t地址\n");
		printf("%-3s\t%-2d\t%-3s\t%-15s%\t%-10s\n",
			con->people[ret].name,
			con->people[ret].age,
			con->people[ret].sex,
			con->people[ret].tele,
			con->people[ret].addr);
		while (1)
		{
			printf("请确认是否删除此人\n1、删除\n2、不删除\n");
			int select = 0;
			scanf("%d", &select);
			if (select == 1)
			{
				for (; ret < con->size-1; ++ret)
				{
					con->people[ret] = con->people[ret + 1];
				}
				con->size--;
				printf("已删除此人(请记得保存此操作)\n");
				break;
			}
			else if (select == 2)
			{
				printf("已退出删除\n");
				break;
			}
			else
			{
				printf("输入错误，请重新输入\n");
			}
		}
	}
}

void searchContact(Contact* con)
{
	printf("请输入查找人的姓名：");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = findContact(con, name);
	if (ret == -1)
	{
		printf("查无此人\n");
		return;
	}
	printf("姓名\t年龄\t性别\t电话\t\t地址\n");
	printf("%-3s\t%-2d\t%-3s\t%-15s%\t%-10s\n",
		con->people[ret].name,
		con->people[ret].age,
		con->people[ret].sex,
		con->people[ret].tele,
		con->people[ret].addr);
}

void sortContact(Contact* con)
{
	int i = 0;
	int j = 0;
	for (; i < con->size - 1; ++i)
	{
		for (; j < con->size - 1; ++j)
		{
			if (con->people[j].age < con->people[j+1].age)
			{
				PeoInFo temp = con->people[j];
				con->people[j] = con->people[j + 1];
				con->people[j + 1] = temp;
			}
		}
	}
	printf("已排序\n");
	save(con);
}

void showContact(Contact* con)
{
	int i = 0;
	if (con->size > 0)
	{
		printf("姓名\t年龄\t性别\t电话\t\t地址\n");
		for (; i < con->size; i++)
		{
			printf("%-3s\t%-2d\t%-3s\t%-15s%\t%-10s\n",
				con->people[i].name,
				con->people[i].age,
				con->people[i].sex,
				con->people[i].tele,
				con->people[i].addr);
		}
	}
	else
	{
		printf("通讯录为空\n");
	}
	
	
}

void capacity(Contact* con)
{
	printf("容量大小为%d", con->capacity);
}

void save(Contact* con)
{
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		printf("save:: % s", strerror(errno));
		return;
	}
	int i = 0;
	for (; i < con->size; ++i)
	{
		fwrite(&con->people[i], sizeof(PeoInFo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}