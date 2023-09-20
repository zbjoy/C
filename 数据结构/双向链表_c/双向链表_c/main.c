#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "DuLinkList.h"

int main()
{
    //system("chcp 65001");
    //printf("ÄãºÃ!\n");

    DuLinkList dl = (DuLinkList)malloc(sizeof(DLNode));
    Init_DuLinkList(dl);
    int i = 7;
    for (; i < 17; i++)
    {
        Insert_DuLinkList(dl, &i);
    }

    Delete_DuLinkList(dl, 1);
    return 0;
}