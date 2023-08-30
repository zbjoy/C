#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void menu()
{
	printf("\t\t\t     **********ѧ������ϵͳ**********\n");
	printf("\t\t\t     *      1���������ѧ����Ϣ     *\n");
	printf("\t\t\t     *      2����ѧ�Ų�ѯѧ����Ϣ   *\n");
	printf("\t\t\t     *      3���޸�ѧ����Ϣ         *\n");
	printf("\t\t\t     *      4�����һ��ѧ����Ϣ     *\n");
	printf("\t\t\t     *      5��ɾ��һ��ѧ����Ϣ     *\n");
	printf("\t\t\t     *      0���˳�ϵͳ             *\n");
	printf("\t\t\t     ********************************\n");
}


static void CheckCapacity(SeqList* list)
{
	if (list->capacity <= list->len)
	{
		datatype* tmp = (datatype*)realloc(list->data, (list->capacity + 1) * sizeof(datatype));
		if (tmp == NULL)
		{
			printf("����ʧ�ܣ�\n");
			return;
		}
		list->data = tmp;
		list->capacity++;
		printf("���ݳɹ�!\n");
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
	//Ϊʲôһ���ѧ���ͻ��˳�
	list->data = (datatype*)malloc(MAXSIZE*sizeof(datatype));
	
	list->len = 0;
	list->capacity = MAXSIZE;

	LoadStudent(list);
}

void printAllStudent(SeqList* list)
{
	int i = 0;
	int j = 0;
	printf("ѧ��\t\t����\t�༶\t�ɼ�\n");
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
	printf("����������˵�ѧ�ţ�");
	scanf("%s", val);
	int ret = findNum(list, val);
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	printf("ѧ��\t\t����\t�༶\t�ɼ�\n");
	printf("%s\t\t%s\t%s\t%d\n",
		list->data[ret].num,
		list->data[ret].name,
		list->data[ret].classname,
		list->data[ret].score);
	
}

void xiugai_Num(SeqList* list)
{
	char val[NUMMAX];
	printf("������Ҫ�޸��˵�ѧ�ţ�");
	scanf("%s", val);
	int ret = findNum(list, val);
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	printf("ѧ��\t\t����\t�༶\t�ɼ�\n");
	printf("%s\t\t%s\t%s\t%d\n",
		list->data[ret].num,
		list->data[ret].name,
		list->data[ret].classname,
		list->data[ret].score);

	int select;
	printf("�Ƿ��޸Ĵ���\n");
	printf("1���޸�\n2��ȡ��\n");
	scanf("%d", &select);
	if (select == 1)
	{
		printf("������Ҫ�޸�ѧ����ѧ��Ϊ��");
		scanf("%s", list->data[ret].num);
		printf("������Ҫ�޸�ѧ��������Ϊ��");
		scanf("%s", list->data[ret].name);
		printf("������Ҫ�޸�ѧ���İ༶����Ϊ��");
		scanf("%s", list->data[ret].classname);
		printf("������Ҫ�޸�ѧ���ĳɼ�Ϊ��");
		scanf("%d", &list->data[ret].score);
	}
	
	else
	{
		printf("��ȡ���޸ģ�\n");
	}
	return;
}

void addStudent(SeqList* list)
{
	//char num[NUMMAX];//ѧ��
	//char name[NAMEMAX];//����
	//char classname[CLASSNAMEMAX];//�༶����
	//int score;//�ɼ�
	CheckCapacity(list);
	printf("������Ҫ���ѧ����ѧ�ţ�");
	scanf("%s", list->data[list->len].num);
	printf("������Ҫ���ѧ����������");
	scanf("%s", list->data[list->len].name);
	printf("������Ҫ���ѧ���İ༶������");
	scanf("%s", list->data[list->len].classname);
	printf("������Ҫ���ѧ���ĳɼ���");
	scanf("%d", &list->data[list->len].score);

	list->len++;

	Save(list);
	printf("��ӳɹ���\n");
}

void deleteStudent(SeqList* list)
{
	char val[NUMMAX];
	printf("������Ҫɾ���˵�ѧ�ţ�");
	scanf("%s", val);
	int ret = findNum(list, val);
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	printf("ѧ��\t\t����\t�༶\t�ɼ�\n");
	printf("%s\t\t%s\t%s\t%d\n",
		list->data[ret].num,
		list->data[ret].name,
		list->data[ret].classname,
		list->data[ret].score);

	int select;
	printf("�Ƿ�ɾ������\n");
	printf("1��ɾ��\n2��ȡ��\n");
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
		printf("ɾ����ȡ��\n");
		return;
	}
}