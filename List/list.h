#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#define NODE_NUM 2000
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

void ShowCopyright ();
void ShowTime ();
Date * InitList ();
void UserInterface ();
char GetOption ();
Date * CreateListRandom (Date*);
void PrintList (Date*);
void SaveToFile ();
void ShowListFile ();
void ShowIllegalNode ();
void DeleteNode ();
void Incert ();
void ShowDays ();
void Sort ();
void PrimeNumberNode ();
void ReverseList ();
void FreeList ();
#endif // list_h__

