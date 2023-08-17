#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define MAX_NAME 7
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 20
#define DEFAULT_SZ 3


#endif



typedef struct PeoInFo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

}PeoInFo;


typedef struct Contact
{
	int size;
	int capacity;
	PeoInFo* people;

}Contact;




void menu();

void CheckCapacity(Contact* con);

void InItContact(Contact* con);

void LoadContact(Contact* con);

void addContact(Contact* con);

void delContact(Contact* con);

void searchContact(Contact* con);

void showContact(Contact* con);

void sortContact(Contact* con);

void capacity(Contact* con);

void save(Contact* con);