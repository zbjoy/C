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
		printf("���ݳɹ�\n");
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
	printf("������Ҫ����˵�������");
	scanf("%s", con->people[con->size].name);
	printf("������Ҫ����˵����䣺");
	scanf("%d", &con->people[con->size].age);
	printf("������Ҫ����˵��Ա�");
	scanf("%s", con->people[con->size].sex);
	printf("������Ҫ����˵ĵ绰��");
	scanf("%s", con->people[con->size].tele);
	printf("������Ҫ����˵ĵ�ַ��");
	scanf("%s", con->people[con->size].addr);
	con->size++;
	save(con);
}

void delContact(Contact* con)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�������");
	scanf("%s", name);
	int ret = findContact(con, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("����\t����\t�Ա�\t�绰\t\t��ַ\n");
		printf("%-3s\t%-2d\t%-3s\t%-15s%\t%-10s\n",
			con->people[ret].name,
			con->people[ret].age,
			con->people[ret].sex,
			con->people[ret].tele,
			con->people[ret].addr);
		while (1)
		{
			printf("��ȷ���Ƿ�ɾ������\n1��ɾ��\n2����ɾ��\n");
			int select = 0;
			scanf("%d", &select);
			if (select == 1)
			{
				for (; ret < con->size-1; ++ret)
				{
					con->people[ret] = con->people[ret + 1];
				}
				con->size--;
				printf("��ɾ������(��ǵñ���˲���)\n");
				break;
			}
			else if (select == 2)
			{
				printf("���˳�ɾ��\n");
				break;
			}
			else
			{
				printf("�����������������\n");
			}
		}
	}
}

void searchContact(Contact* con)
{
	printf("����������˵�������");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = findContact(con, name);
	if (ret == -1)
	{
		printf("���޴���\n");
		return;
	}
	printf("����\t����\t�Ա�\t�绰\t\t��ַ\n");
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
	printf("������\n");
	save(con);
}

void showContact(Contact* con)
{
	int i = 0;
	if (con->size > 0)
	{
		printf("����\t����\t�Ա�\t�绰\t\t��ַ\n");
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
		printf("ͨѶ¼Ϊ��\n");
	}
	
	
}

void capacity(Contact* con)
{
	printf("������СΪ%d", con->capacity);
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