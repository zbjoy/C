#define _CRT_SECURE_NO_WARNINGS 1

#include "bingfang.h"

//list* initList(list* head)
//{
//	head = (list*)malloc(sizeof(list));
//	head->next = NULL;
//	return head;
//}

list* CreateListF(list* head)
{
	int i = 0;
	int n;
	list* s;
	printf("������Ҫ��ӵĲ���������");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		s = (list*)malloc(sizeof(list));
		s->next = head->next;
		head->next = s;
		printf("�������%dλ���˵���Ϣ��\n", i + 1);
		printf("�����벡�˵Ĳ��ţ�");
		scanf("%s", s->data.num);
		printf("�����벡�˵�������");
		scanf("%s", s->data.name);
		printf("�����벡�˵ĵ绰��");
		scanf("%s", s->data.tele);
		printf("�����벡�˵ĵ�ַ��");
		scanf("%s", s->data.addr);
	}
	return head;
}

list* CreateListR(list* head)
{
	int i = 0;
	int n;
	list* s = (list*)malloc(sizeof(list));
	s = head;
	printf("������Ҫ��ӵĲ���������");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		s->next = (list*)malloc(sizeof(list));
		s = s->next;
		printf("�������%dλ���˵���Ϣ��\n", i + 1);
		printf("�����벡�˵Ĳ��ţ�");
		scanf("%s", s->data.num);
		printf("�����벡�˵�������");
		scanf("%s", s->data.name);
		printf("�����벡�˵ĵ绰��");
		scanf("%s", s->data.tele);
		printf("�����벡�˵ĵ�ַ��");
		scanf("%s", s->data.addr);
	}
	s->next = NULL;
	return head;
}

void showPatient(list* head)
{
	list* t = head;
	//if (head->next = NULL)
	if(head->next == NULL)
	{
		printf("�޲�����Ϣ\n");
		return;
	}
	printf("����\t\t����\t�绰\t\t��ַ\n");
	while (t->next != NULL)
	{
		t = t->next;
		printf("%-12s\t%-5s\t%-12s\t%-15s\n",
			t->data.num,
			t->data.name,
			t->data.tele,
			t->data.addr);
	}
	return;
}

void insertPatient(list* head)
{
	int pos = 0;
	int i = 0;
	printf("����������λ�ã�\n");
	printf("���뵽��:");
	scanf("%d", &pos);
	for(i = 1;i < pos; ++i)
	{
		head = head->next;
	}
	list* p = (list*)malloc(sizeof(list));
	p->next = head->next;
	head->next = p;
	printf("�����벡�˵Ĳ��ţ�");
	scanf("%s", p->data.num);
	printf("�����벡�˵�������");
	scanf("%s", p->data.name);
	printf("�����벡�˵ĵ绰��");
	scanf("%s", p->data.tele);
	printf("�����벡�˵ĵ�ַ��");
	scanf("%s", p->data.addr);

	printf("����ɹ�\n");
}

void deletePatient(list* head)
{
	int pos = 0;
	int i = 0;
	printf("������ɾ����λ�ã�\n");
	printf("ɾ����:");
	scanf("%d", &pos);
	for (i = 1; i < pos; ++i)
	{
		head = head->next;
	}
	list* p = (list*)malloc(sizeof(list));
	p = head->next;//��ô����free��headָ���next������ָ��head->next->next
	head->next = p->next;
	free(p);
	p = NULL;//����������
}