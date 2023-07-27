#define _CRT_SECURE_NO_WARNINGS 1


#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>
#include <string>

using namespace std;

#endif



struct People
{
	char name[10];
	int age;
	char gender[5];
	char tele[12];
	char addr[20];
};
struct Contact
{
	struct People* data;
	int size;
	int capacity;
};



void menu();
void ContactInIt(struct Contact* p);
void AddContact(struct Contact* p);
void ShowContact(struct Contact* p);
void FindContact(struct Contact* p);
int FindPos(struct Contact* p,string name);
void DelContact(Contact* p);
void SaveContact(Contact* p);