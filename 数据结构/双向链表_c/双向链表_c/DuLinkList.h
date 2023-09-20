#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct LNode
{
    DataType data;
    struct LNode* next;
    struct LNode* prior;
}DLNode, * DuLinkList;

void Init_DuLinkList(DuLinkList dl);

int Insert_DuLinkList(DuLinkList dl, DataType* px);

int Delete_DuLinkList(DuLinkList dl, int pos);
