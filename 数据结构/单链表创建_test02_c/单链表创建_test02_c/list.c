#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node
{
	DataType data;
	struct node* next;
}LNode,*LinkList;

LinkList CreateListF(LinkList head)
{
	int i, n;
	//head = (LinkList)malloc(sizeof(LNode));
	//head->next = NULL;
	LinkList s;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->next = head->next;
		head->next = s;
		scanf("%d", &s->data);
	}
	return head;
}

LinkList CreateListR(LinkList head)
{
	LinkList s = head;
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		s->next = (LinkList)malloc(sizeof(LNode));
		s = s->next;
		scanf("%d", &s->data);
	}
	s->next = NULL;
	return head;
}

int main()
{
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	//head = CreateListF(head);
	head = CreateListR(head);

	return 0;
}