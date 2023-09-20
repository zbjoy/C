#define _CRT_SECURE_NO_WARNINGS 1

#include "DuLinkList.h"

void Init_DuLinkList(DuLinkList dl)
{
    dl->prior = NULL;
    dl->next = (DuLinkList)malloc(sizeof(DLNode));
    dl->next->next = dl->next->prior = NULL;
}

int Insert_DuLinkList(DuLinkList dl, DataType* px)
{
    DuLinkList t = (DuLinkList)malloc(sizeof(DLNode));
    assert(t);
    t->data = *px;
    t->next = dl->next;
    t->prior = dl;
    t->next->prior = t;
    t->prior->next = t;
    return 1;
}

int Delete_DuLinkList(DuLinkList dl, int pos)
{
    DuLinkList t;
    while (pos--)
    {
        dl = dl->next;
    }
    t = dl;
    dl->prior->next = t->next;
    dl->next->prior = t->prior;
    free(t);

    return 1;
}
