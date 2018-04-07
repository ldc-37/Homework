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
//显示版权信息
void ShowCopyright ();
//显示当前时间
void ShowTime ();
//初始化链表
Date * InitList ();
//主页面
void UserInterface ();
//创建随机数据的节点
Date * CreateListRandom (Date*);
//输出所有链表或前x个节点的数据
void PrintList (Date*);

//保存链表数据至文件
void SaveToFile (Date*);
//从文件中读取数据并分屏展示
void ShowListFile (Date*);

//显示不合法日期节点
void ShowIllegalNode (Date*);
//删除头、尾、非法节点
void DeleteNode (Date*);

//插入链表
void Insert (Date*);
//将当前日期插入头/尾节点等
void InsertFirst (Date*, Date*);
void InsertLast (Date*, Date*);
void InsertBefore (Date*, Date*);
void InsertAfter (Date*, Date*);

//输出所有节点日期距离1900.1.1的天数
void ShowTotalDays (Date*);
//计算某节点日期距离1900.1.1的天数
int CountDays (Date*);

//交换两个节点的数据
void Swap (Date*, Date*);
//按日期从小到大排序链表
void Sort (Date*);
//隐藏/显示光标
void HideCursor ();
void ShowCursor ();

//输出年月日均为素数的节点
void PrimeNumberNode (Date*);

//反转链表
void ReverseList (Date*);

//清空链表
void FreeList (Date*);

/** Judge function **/
bool IsReapYear (int);
bool IsIllegalDate (Date*);
bool IsEmptyLink (Date*);
bool IsPrimeNumber (int);

/** Assist  function**/
//即时获取用户输入
bool GetOptionYN ();
char GetOption (Date*);
//计算节点数量
int NodeNum (Date*);

#endif // list_h__