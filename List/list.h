#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime> //use to get time
#include <conio.h> // use to get key-event
#include <cmath> // use to judge prime number
#include <iomanip> //format output from file
#include <Windows.h> //show or hide cursor in console

#define INIT_NODE_NUM 2000

#define MIN_YEAR 1900
#define MAX_YEAR 2300
#define MONTH_NUM 12
#define DAY_NUM 31

#define LINE_LENGTH 80
#define PAGE_LINE 25

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

/** Main **/
//��ʾ��Ȩ��Ϣ
void ShowCopyright ();
//��ʾ��ǰʱ��
void ShowTime ();
//��ʼ������
Date * InitList ();
//��ҳ��
void UserInterface ();
//����������ݵĽڵ�
Date * CreateListRandom (Date*);
//������������ǰx���ڵ������
void PrintList (Date*);

//���������������ļ�
void SaveToFile (Date*);
//���ļ��ж�ȡ���ݲ�����չʾ
void ShowListFile (Date*);

//��ʾ���Ϸ����ڽڵ�
void ShowIllegalNode (Date*);
//ɾ��ͷ��β���Ƿ��ڵ�
void DeleteNode (Date*);

//��������
void Insert (Date*);
//����ǰ���ڲ���ͷ/β�ڵ��
void InsertFirst (Date*, Date*);
void InsertLast (Date*, Date*);
void InsertBefore (Date*, Date*);
void InsertAfter (Date*, Date*);

//������нڵ����ھ���1900.1.1������
void ShowTotalDays (Date*);
//����ĳ�ڵ����ھ���1900.1.1������
int CountDays (Date*);

//���������ڵ������
void Swap (Date*, Date*);
//�����ڴ�С������������
void Sort (Date*);
//����/��ʾ���
void HideCursor ();
void ShowCursor ();

//��������վ�Ϊ�����Ľڵ�
void PrimeNumberNode (Date*);

//��ת����
void ReverseList (Date*);

//�������
void FreeList (Date*);

/** Judge function **/
bool IsReapYear (int);
bool IsIllegalDate (Date*);
bool IsEmptyLink (Date*);
bool IsPrimeNumber (int);

/** Assist  function**/
//��ʱ��ȡ�û�����
bool GetOptionYN ();
char GetOption (Date*);
//����ڵ�����
int NodeNum (Date*);

#endif // list_h__