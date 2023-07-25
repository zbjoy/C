#define _CRT_SECURE_NO_WARNINGS 1

//#define MAX 10
#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 10
#define DEFAULT_SZ 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

struct PeoInFo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct Contact
{
	//struct PeoInFo data[MAX];
	struct PeoInFo* data;
	int size;
	int capacity;
};
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact_Byage(struct Contact* ps);
void CheckContact(struct Contact* ps);
void QuestionCapacity(const struct Contact* ps);
void DestroyContact(struct Contact* ps);
void SaveContact(struct Contact* ps);
void LoadContact(struct Contact* ps);
