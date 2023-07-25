#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
static int FindContact(const struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(name, ps->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void CheckContact(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInFo* ptr = realloc(ps->data,(ps->capacity+1)*sizeof(struct PeoInFo) );
		if (ptr != NULL)
		{
			ps->data=ptr;
			ps->capacity++;
			printf("���ݳɹ�\n");
		}
	}
}
void LoadContact(struct Contact* ps)
{
	struct PeoInFo tmp = { 0 };
	FILE* pfRead = fopen("contact.tab", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct PeoInFo), 1, pfRead))
	{
		CheckContact(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}
void InitContact(struct Contact* ps)
{
	//memset(ps->data, 0, sizeof(ps->data));
	//ps->size = 0;
	ps->data= (struct PeoInFo*)malloc(DEFAULT_SZ*sizeof(struct PeoInFo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}
void AddContact(struct Contact* ps)
{
	//if (ps->size >= MAX)
	//{
	//		printf("��Ա�������޷����\n");
	//}
	//else
	//{
	//		printf("������������");
    //		scanf("%s", ps->data[ps->size].name);
    //		printf("���������䣺");
    //		scanf("%d", &(ps->data[ps->size].age));
    //		printf("�������Ա�");
	//		scanf("%s", ps->data[ps->size].sex);
	//		printf("������绰��");
	//		scanf("%s", ps->data[ps->size].tele);
	//		printf("�������ַ��");
	//		scanf("%s", ps->data[ps->size].addr);
	//		printf("��ӳɹ�\n");
	//		ps->size++;
	//}
	CheckContact(ps);
	printf("������������");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->data[ps->size].addr);
	printf("��ӳɹ�\n");
	ps->size++;
}
void ShowContact(const struct Contact* ps)
{
	int i = 0;
	printf("%-10s\t%-5s\t%-3s\t%-20s\t%-15s\n","����","����","�Ա�","�绰","��ַ");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-10s\t%-5d\t%-3s\t%-20s\t%-15s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME] = "0";
	printf("������Ҫɾ�����˵�������");
	scanf("%s", name);
	int pos=FindContact(ps,name);
	if (pos == -1)
	{
		printf("��Ҫɾ�����˲�����\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < ps->size; i++)
		{
			ps->data[i] = ps->data[i+1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ���������");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-3s\t%-20s\t%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t%-5d\t%-3s\t%-20s\t%-15s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME] = "0";
	printf("��������Ҫ�޸��˵�������");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("�鵽���ˣ�\n");
		printf("%-10s\t%-5s\t%-3s\t%-20s\t%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t%-5d\t%-3s\t%-20s\t%-15s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
		printf("�������޸ĺ����Ϣ��\n");
		printf("������������");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}
void SortContact_Byage(struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->data[j].age < ps->data[j + 1].age)
			{
				struct PeoInFo tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
	printf("������ɣ�����������\n");
}
void QuestionCapacity(const struct Contact* ps)
{
	printf("%d\n", ps->capacity);
}
void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = 0;
}
void SaveContact(struct Contact* ps)
{
	int i = 0;
	FILE* pfWrite = fopen("contact.tab", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&ps->data[i], sizeof(struct PeoInFo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}