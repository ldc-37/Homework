#include <iostream>
#include <cstdlib>
#include <ctime> //use to get time
#include <conio.h> // use to get key-event
#include <cmath> // use to judge prime number

#define INIT_NODE_NUM 2000
#define MIN_YEAR 1900
#define MAX_YEAR 2300
#define MONTH_NUM 12
#define DAY_NUM 31


#ifndef _NODE_DEFINED
typedef struct Date
{
    int year;
    int month;
    int day;
    Date *next;
}date;
#define _NODE_DEFINED
#endif // !_NODE_DEFINED

#ifndef _DAYOFMONTH_DEFINED
const int dayOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
#define _DAYOFMONTH_DEFINED
#endif // !_DAYOFMONTH_DEFINED


#ifndef list_h__
#define list_h__

//Main
void ShowCopyright ();
void ShowTime ();
Date * InitList ();
void UserInterface ();
Date * CreateListRandom (Date*);
void PrintList (Date*);
void SaveToFile ();
void ShowListFile ();

bool IsReapYear (int);
bool IsIllegalDate (Date*);
void ShowIllegalNode (Date*);
void DeleteNode (Date*);

void Incert ();

void ShowTotalDays (Date*);
int CountDays (Date*);

void Sort ();

bool IsPrimeNumber (int);
void PrimeNumberNode (Date*);

void ReverseList (Date*);
void FreeList (Date*);

//Assist
bool GetOptionYN ();
char GetOption (Date*);
bool IsEmptyLink (Date*);
int NodeNum (Date*);
#endif // list_h__

