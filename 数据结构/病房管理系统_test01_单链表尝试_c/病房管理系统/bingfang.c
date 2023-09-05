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
	printf("请输入要添加的病人数量：");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		s = (list*)malloc(sizeof(list));
		s->next = head->next;
		head->next = s;
		printf("请输入第%d位病人的信息：\n", i + 1);
		printf("请输入病人的病号：");
		scanf("%s", s->data.num);
		printf("请输入病人的姓名：");
		scanf("%s", s->data.name);
		printf("请输入病人的电话：");
		scanf("%s", s->data.tele);
		printf("请输入病人的地址：");
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
	printf("请输入要添加的病人数量：");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		s->next = (list*)malloc(sizeof(list));
		s = s->next;
		printf("请输入第%d位病人的信息：\n", i + 1);
		printf("请输入病人的病号：");
		scanf("%s", s->data.num);
		printf("请输入病人的姓名：");
		scanf("%s", s->data.name);
		printf("请输入病人的电话：");
		scanf("%s", s->data.tele);
		printf("请输入病人的地址：");
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
		printf("无病人信息\n");
		return;
	}
	printf("病号\t\t姓名\t电话\t\t地址\n");
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
	printf("请输入插入的位置：\n");
	printf("插入到第:");
	scanf("%d", &pos);
	for(i = 1;i < pos; ++i)
	{
		head = head->next;
	}
	list* p = (list*)malloc(sizeof(list));
	p->next = head->next;
	head->next = p;
	printf("请输入病人的病号：");
	scanf("%s", p->data.num);
	printf("请输入病人的姓名：");
	scanf("%s", p->data.name);
	printf("请输入病人的电话：");
	scanf("%s", p->data.tele);
	printf("请输入病人的地址：");
	scanf("%s", p->data.addr);

	printf("插入成功\n");
}

void deletePatient(list* head)
{
	int pos = 0;
	int i = 0;
	printf("请输入删除的位置：\n");
	printf("删除第:");
	scanf("%d", &pos);
	for (i = 1; i < pos; ++i)
	{
		head = head->next;
	}
	list* p = (list*)malloc(sizeof(list));
	p = head->next;//怎么才能free掉head指向的next再让它指向head->next->next
	head->next = p->next;
	free(p);
	p = NULL;//这样可以吗？
}