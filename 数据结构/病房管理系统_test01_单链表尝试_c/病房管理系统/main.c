#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include "bingfang.h"

int main()
{
	list* l = (list*)malloc(sizeof(list));
	l->next = NULL;
	//l = CreateListF(l);
	l = CreateListR(l);
	showPatient(l);
	insertPatient(l);
	deletePatient(l);
	return 0;
}