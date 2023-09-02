#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

void menu()
{
	printf("\t\t\t     *****************ѧ������ϵͳ**************\n");
	printf("\t\t\t     *          1���������ѧ����Ϣ            *\n");
	printf("\t\t\t     *          2����ѧ�Ż�������ѯѧ����Ϣ    *\n");
	printf("\t\t\t     *          3���޸�ѧ����Ϣ                *\n");
	printf("\t\t\t     *          4�����һ��ѧ����Ϣ            *\n");
	printf("\t\t\t     *          5��ɾ��һ��ѧ����Ϣ            *\n");
	printf("\t\t\t     *          0���˳�ϵͳ                    *\n");
	printf("\t\t\t     *******************************************\n");
}

void LoadStudent(SeqList* psl)//��"student.txt"�ļ��н���Ϣ��ȡ����
{
	FILE* pfread = fopen("student.txt", "rb");
	if (pfread == NULL)
	{
		printf("LoadStudent::%s", strerror(errno));
		return;
	}

	student temp;
	while (fread(&temp, sizeof(student), 1, pfread));//���˸�;��������ֻ������һ��!!!!!!!!
	while (fread(&temp, sizeof(student), 1, pfread))
	{
		CheckCapacity(psl);
		psl->data[psl->size] = temp;
		psl->size++;
	}

	fclose(pfread);
	pfread = NULL;
}

void InItSeqList(SeqList* psl)//��ʼ��
{
	psl->data = (student*)malloc(STARTCAP * sizeof(student));

	if (psl == NULL)
	{
		return;
	}
	psl->size = 0;
	psl->capacity = STARTCAP;

	LoadStudent(psl);//����student.txt�е��ļ���psl��

}

void CheckCapacity(SeqList* psl)//��������Ƿ��㹻������realloc����ռ�
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
		printf("���ݳɹ�\n");
	}
}

void saveStudent(SeqList* psl)//����ѧ����Ϣ��student.txt�ļ�
{
	FILE* pfwrite = fopen("student.txt", "wb");
	if (fwrite == NULL)
	{
		printf("saveStudent::%s", strerror(errno));//�жϴ���ԭ��
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


void print(SeqList* psl)//��ӡ����student��Ϣ
{
	if (psl->size == 0)
	{
		printf("��ѧ����Ϣ\n");
		return;
	}
	//system("chcp 65001");
	int i = 0;
	printf("ѧ��\t\t����\t�Ա�\t�༶\t\t��ϵ�绰\t\tC���Գɼ�\n");
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

int findStudent_Num(SeqList* psl, char Num[NUMMAX])//��ѧ�Ų��ң�����λ��i
{
	int i = 0;
	for (; i < psl->size; ++i)
	{
		if (!strcmp(psl->data[i].m_Num, Num))
		{
			return i;
		}
	}

	return -1;//û�в鵽����-1
}

int findStudent_Name(SeqList* psl, char Name[NAMEMAX])//���������ң�����λ��i
{
	int i = 0;
	for (; i < psl->size; ++i)
	{
		if (!strcmp(psl->data[i].m_Name, Name))
		{
			return i;
		}
	}

	return -1;//û�в鵽����-1
}

void findStudent(SeqList* psl)//��ѧ�Ż�������ѯѧ����Ϣ
{
	while (1)
	{
		int select;
		printf("��������Ĳ�ѯ��ʽ��\n");
		printf("1����ѧ�Ų�ѯ\n2����������ѯ\n");
		scanf("%d", &select);
		int ret = 0;

		if (select == 1)//��ѧ�Ų�ѯ
		{
			char Num[NUMMAX];
			printf("������Ҫ����ѧ����ѧ�ţ�");
			scanf("%s", Num);
			ret = findStudent_Num(psl, Num);
		}
		else if (select == 2)//��������ѯ
		{
			char Name[NAMEMAX];
			printf("������Ҫ����ѧ����������");
			scanf("%s", Name);
			ret = findStudent_Name(psl, Name);
		}
		else
		{
			printf("�����������������\n");
			continue;
		}

		if (ret == -1)
		{
			printf("���޴���\n");
		}
		else
		{
			printf("ѧ��\t\t����\t�Ա�\t�༶\t\t��ϵ�绰\t\tC���Գɼ�\n");
			printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
				psl->data[ret].m_Num,
				psl->data[ret].m_Name,
				psl->data[ret].m_Sex,
				psl->data[ret].m_ClassName,
				psl->data[ret].m_Tele,
				psl->data[ret].m_Score);
		}

		printf("�Ƿ������ѯ��\n");
		printf("1��������ѯ\n2��������ѯ\n");
		scanf("%d", &select);

		if (select == 2)
		{
			break;
		}
	}
	
}

void modifyStudent(SeqList* psl)//�޸�ѧ����Ϣ
{
	while (1)
	{
		int select;
		printf("��������Ĳ�ѯҪ�޸�ѧ����ʽ��\n");
		printf("1����ѧ�Ų�ѯ\n2����������ѯ\n");
		scanf("%d", &select);
		int ret = 0;

		if (select == 1)//��ѧ�Ų�ѯ
		{
			char Num[NUMMAX];
			printf("������Ҫ�޸�ѧ����ѧ�ţ�");
			scanf("%s", Num);
			ret = findStudent_Num(psl, Num);
		}
		else if (select == 2)//��������ѯ
		{
			char Name[NAMEMAX];
			printf("������Ҫ�޸�ѧ����������");
			scanf("%s", Name);
			ret = findStudent_Name(psl, Name);
		}
		else
		{
			printf("�����������������\n");
			continue;
		}

		if (ret == -1)
		{
			printf("���޴���\n");
		}
		else
		{
			printf("ѧ��\t\t����\t�Ա�\t�༶\t\t��ϵ�绰\t\tC���Գɼ�\n");
			printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
				psl->data[ret].m_Num,
				psl->data[ret].m_Name,
				psl->data[ret].m_Sex,
				psl->data[ret].m_ClassName,
				psl->data[ret].m_Tele,
				psl->data[ret].m_Score);
		}

		int t = 0;
		printf("�Ƿ��޸Ĵ��ˣ�\n");
		printf("1���޸Ĵ���\n2��ȡ���޸�\n");
		scanf("%d", &t);
		if (t == 1)//�޸Ĵ���
		{
			printf("�������޸ĺ�ѧ����ѧ�ţ�");
			scanf("%s", psl->data[psl->size].m_Num);
			printf("�������޸ĺ�ѧ����������");
			scanf("%s", psl->data[psl->size].m_Name);
			printf("�������޸ĺ�ѧ�����Ա�");
			scanf("%s", psl->data[psl->size].m_Sex);
			printf("�������޸ĺ�ѧ���İ༶������");
			scanf("%s", psl->data[psl->size].m_ClassName);
			printf("�������޸ĺ�ѧ������ϵ�绰��");
			scanf("%s", psl->data[psl->size].m_Tele);
			printf("�������޸ĺ�ѧ����C���Գɼ���");
			scanf("%d", &psl->data[psl->size].m_Score);
			printf("�޸ĳɹ�\n");
		}
		else
		{
			printf("��ȡ���޸�");
		}

		printf("�Ƿ�����޸ģ�\n");
		printf("1�������޸�\n2�������޸�\n");
		scanf("%d", &select);

		if (select == 2)
		{
			break;
		}
	}
}

void addStudent(SeqList* psl)//���ѧ����Ϣ
{
	CheckCapacity(psl);

	printf("������Ҫ���ѧ����ѧ�ţ�");
	scanf("%s", psl->data[psl->size].m_Num);
	printf("������Ҫ���ѧ����������");
	scanf("%s", psl->data[psl->size].m_Name);
	printf("������Ҫ���ѧ�����Ա�");
	scanf("%s", psl->data[psl->size].m_Sex);
	printf("������Ҫ���ѧ���İ༶������");
	scanf("%s", psl->data[psl->size].m_ClassName);
	printf("������Ҫ���ѧ������ϵ�绰��");
	scanf("%s", psl->data[psl->size].m_Tele);
	printf("������Ҫ���ѧ����C���Գɼ���");
	scanf("%d", &psl->data[psl->size].m_Score);

	psl->size++;
	saveStudent(psl);
	printf("��ӳɹ�\n");
}

void deleteStudent(SeqList* psl)//ɾ��ѧ����Ϣ
{
	while (1)
	{
		int select;
		printf("��������Ĳ�ѯҪɾ��ѧ����ʽ��\n");
		printf("1����ѧ�Ų�ѯ\n2����������ѯ\n");
		scanf("%d", &select);
		int ret = 0;

		if (select == 1)//��ѧ�Ų�ѯ
		{
			char Num[NUMMAX];
			printf("������Ҫɾ��ѧ����ѧ�ţ�");
			scanf("%s", Num);
			ret = findStudent_Num(psl, Num);
		}
		else if (select == 2)//��������ѯ
		{
			char Name[NAMEMAX];
			printf("������Ҫɾ��ѧ����������");
			scanf("%s", Name);
			ret = findStudent_Name(psl, Name);
		}
		else
		{
			printf("�����������������\n");
			continue;
		}

		if (ret == -1)
		{
			printf("���޴���\n");
		}
		else
		{
			printf("ѧ��\t\t����\t�Ա�\t�༶\t\t��ϵ�绰\t\tC���Գɼ�\n");
			printf("%-12s\t%-5s\t%-5s\t%-5s\t\t%-12s\t\t%-3d\n",
				psl->data[ret].m_Num,
				psl->data[ret].m_Name,
				psl->data[ret].m_Sex,
				psl->data[ret].m_ClassName,
				psl->data[ret].m_Tele,
				psl->data[ret].m_Score);
		}

		int t = 0;
		printf("�Ƿ�ɾ�����ˣ�\n");
		printf("1��ɾ������\n2��ȡ��ɾ��\n");
		scanf("%d", &t);
		if (t == 1)//ɾ������
		{
			int j = ret;
			for (; j < psl->size - 1; ++j)
			{
				psl->data[j] = psl->data[j + 1];
			}

			psl->size--;
			printf("ɾ���ɹ�\n");

			
		}
		else
		{
			printf("��ȡ��ɾ��");
		}

		printf("�Ƿ����ɾ����\n");
		printf("1������ɾ��\n2������ɾ��\n");
		scanf("%d", &select);

		if (select == 2)
		{
			break;
		}
	}
}

void DestroyContact(SeqList* psl)//���ȫ��������student.txt��
{
	free(psl);
	psl = NULL;
	printf("���������ѧ����Ϣ\n");
}