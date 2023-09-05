#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define NUMMAX 12
#define NAMEMAX 15
#define TELEMAX 12
#define ADDRMAX 20

typedef struct patient
{
	char num[NUMMAX];
	char name[NAMEMAX];
	char tele[TELEMAX];
	char addr[ADDRMAX];
}patient;

typedef struct list
{
	patient data;
	struct list* next;
}list;

//list* initList(list* head);

list* CreateListF(list* head);

list* CreateListR(list* head);

void showPatient(list* head);

void insertPatient(list* head);

void deletePatient(list* head);