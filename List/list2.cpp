#include "list.h"

using namespace std;

void ShowCopyright ()
{
    cout << "Copyright (c) 2017-2018 李定成(221701331). All Rights Reserved." << endl << endl;
}
void ShowTime ()
{
    time_t now = time (0);
    struct tm nowTime;
    localtime_s (&nowTime, &now);
    int hour = nowTime.tm_hour;
    int min = nowTime.tm_min;
    int sec = nowTime.tm_sec;
    int year = 1900 + nowTime.tm_year;
    int month = 1 + nowTime.tm_mon;
    int day = nowTime.tm_mday;
    int weekNum = nowTime.tm_wday;
    const char *weekChn[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    const char *week = weekChn[weekNum];

    cout << "当前日期时间：" << year << '.' << month << '.' << day << '(' << week << ") ";
    cout << (hour < 10 ? "0" : "") << hour << ':' << (min < 10 ? "0" : "") << min << ':' << (sec < 10 ? "0" : "") << sec << endl;

}
void UserInterface ()
{
    cout << "****************************************************************" << endl <<
        "*    C : 创建一个存放日期数据的 (无序)链表                     *" << endl <<
        "*    O : 显示链表前几个结点的日期数据                          *" << endl <<
        "*    S : 将整个链表的所有数据存入文件中                        *" << endl <<
        "*    X : 分屏显示日期数据文件的 (全部)内容                     *" << endl <<
        "*    N : 显示不能构成合法日期的 (所有)结点                     *" << endl <<
        "*    D : 删除链表的第一个、最后一个、不能构成合法日期的结点    *" << endl <<
        "*    I : 插入结点 (至链头、链尾、结点之前、结点之后)           *" << endl <<
        "*    T : 显示结点的日期对应的天数                              *" << endl <<
        "*    A : 链表按日期从小到大排序                                *" << endl <<
        "*    P : 查找链表中\"年月日\"都是素数的结点                      *" << endl <<
        "*    F : (单向)链表翻转                                        *" << endl <<
        "*    Z : 清空链表                                              *" << endl <<
        "*    Q : 退出系统                                              *" << endl <<
        "****************************************************************" << endl <<
        "请选择 (C, O, S, X, N, D, I, T, A, P, F, Z, Q) : ";
}

char GetOption (Date * head)
{
    char key;
    while (1) {
        if (_kbhit ()) {
            key = _getch ();
            if (key == 'q' || key == 'Q') {
                FreeList (head);
                exit (0);
            }
            else if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z') {
                if (key >= 'a' && key <= 'z') {
                    key -= 32;
                }
                cout << key << endl;
                return key;
                break;
            }
        }
    }
}
bool GetOptionYN () {
    char key;
    while (1) {
        if (_kbhit ()) {
            key = _getch ();
            cout << key;
            if (key == 'y' || key == 'Y') {
                return true;
            }
            else if (key == 'n' || key == 'N') {
                return false;
            }
            else {
                cout << endl << "请输入正确选项(y/n)" << endl;
            }
        }
    }
}

Date * InitList ()
{
    Date * head = (Date*)malloc (sizeof (Date));
    if (head == NULL) {
        cerr << "申请内存空间失败" << endl;
        return NULL;
    }
    head->next = NULL;
    return head;
}
Date * CreateListRandom (Date * head)
{
    cout << "正在生成……" << endl;
    Date * p;
    srand ((unsigned int)(time (NULL)));
    for (int i = 0; i < INIT_NODE_NUM; ++i) {
        p = (Date*)malloc (sizeof (Date));
        if (p == NULL) {
            cerr << "申请内存空间失败" << endl;
            return NULL;
        }
        p->year = MIN_YEAR + rand () % (MAX_YEAR - MIN_YEAR + 1);
        p->month = 1 + rand () % MONTH_NUM;
        p->day = 1 + rand () % DAY_NUM;
        p->next = head->next;
        head->next = p;
    }
    cout << "生成" << INIT_NODE_NUM << "个日期节点完毕！" << endl;
    return head;
}

void PrintList (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    int num;
    int nodeNum = NodeNum (head);
    bool legal;
    do {
        cout << "请输入要查看的节点数量,输入0为全部：";
        cin >> num;
        if (num == 0) {
            num = nodeNum;
        }
        legal = num > 0 && num <= nodeNum;
        if (!legal) {
            cout << "非法输入，请重新输入" << endl;
            cin.clear ();
            cin.ignore (1024, '\n');
        }
    } while (!legal);
    Date * p = head->next;
    for (int i = 0; i < num; ++i) {
        cout << p->year << '.' << ((p->month < 10) ? "0" : "") << p->month << '.' << ((p->day < 10) ? "0" : "") << p->day << '\t';
        p = p->next;
        if (i % 6 == 5) {
            cout << endl;
        }
    }
}

void ShowIllegalNode (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    Date * p = head->next;
    int i = 0;
    cout << "不合法的日期如下：" << endl;
    do
    {
        if (IsIllegalDate (p)) {
            cout << p->year << '.' << ((p->month < 10) ? "0" : "") << p->month << '.' << ((p->day < 10) ? "0" : "") << p->day << '\t';
            if (++i % 6 == 0) {
                cout << endl;
            }
        }
        p = p->next;
    } while (p != NULL);
    if (i == 0) {
        cout << "没有不合法日期或不合法日期已被删除" << endl;
    }
}
void DeleteNode (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    Date * first = head->next;
    head->next = head->next->next;
    free (first);
    first = NULL;
    Date * last = head;
    while (last->next->next != NULL) {
        last = last->next;
    }
    free (last->next);
    last->next = NULL;

    Date * pre = head, *p = pre->next;
    int numDeleted = 0;
    while (p != NULL) {
        if (IsIllegalDate (p)) {
            pre->next = p->next;
            free (p);
            p = pre->next;
            numDeleted++;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    cout << "删除完成！共删除" << 2 + numDeleted << "个节点" << endl;
}

int CountDays (Date * p)
{
    int totalDays = 0;
    for (int i = MIN_YEAR; i < p->year; ++i) {
        IsReapYear (i) ? totalDays += 366 : totalDays += 365;
    }
    for (int i = 0; i < p->month - 1; ++i) {
        totalDays += dayOfMonth[i];
    }
    if (IsReapYear (p->year) && (p->month >= 3 || p->month == 2 && p->day == 29)) {
        totalDays++;
    }
    totalDays += p->day;
    return totalDays;
}
void ShowTotalDays (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    int i = 0;
    Date * p = head->next;
    while (p != NULL) {
        cout << CountDays (p) << '\t';
        if (++i % 6 == 0) {
            cout << endl;
        }
        p = p->next;
    }
}

void PrimeNumberNode (Date * head) {
    if (IsEmptyLink (head)) {
        return;
    }
    cout << "素数节点如下：" << endl;
    Date * p = head->next;
    int i = 0;
    while (p != NULL) {
        if (IsPrimeNumber (p->year) && IsPrimeNumber (p->month) && IsPrimeNumber (p->day)) {
            cout << p->year << '.' << ((p->month < 10) ? "0" : "") << p->month << '.' << ((p->day < 10) ? "0" : "") << p->day << '\t';
            if (++i % 6 == 0) {
                cout << endl;
            }
        }
        p = p->next;
    }
}

void Insert (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    time_t now = time (0);
    struct tm nowTime;
    localtime_s (&nowTime, &now);
    Date * today = (Date*)malloc (sizeof (Date));
    if (today == NULL) {
        cerr << "申请内存空间失败" << endl;
        return;
    }
    today->year = nowTime.tm_year + 1900;
    today->month = nowTime.tm_mon + 1;
    today->day = nowTime.tm_mday;
    today->next = NULL;
    InsertFirst (today, head);
    InsertLast (today, head);
    InsertAfter (today, head);
    InsertBefore (today, head);
    cout << "已将当前日期插入链表" << endl;
}
void InsertFirst (Date * today, Date * head)
{
    Date * first = (Date*)malloc (sizeof (Date));
    if (first == NULL) {
        cerr << "申请内存空间失败" << endl;
        return;
    }
    first->year = today->year;
    first->month = today->month;
    first->day = today->day;
    first->next = head->next;
    head->next = first;
}
void InsertLast (Date * today, Date * head)
{
    Date * p = head->next;
    Date * last = (Date*)malloc (sizeof (Date));
    if (last == NULL) {
        cerr << "申请内存空间失败" << endl;
        return;
    }
    last->year = today->year;
    last->month = today->month;
    last->day = today->day;
    last->next = NULL;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = last;
}
void InsertAfter (Date * today, Date * head)
{
    Date * p = head->next;
    Date * after = (Date*)malloc (sizeof (Date));
    if (after == NULL) {
        cerr << "申请内存空间失败" << endl;
        return;
    }
    after->year = today->year;
    after->month = today->month;
    after->day = today->day;
    after->next = NULL;
    int days = CountDays (after);
    while (CountDays (p) >= days) {
        p = p->next;
    }
    after->next = p->next;
    p->next = after;
}
void InsertBefore (Date * today, Date * head)
{
    Date * pre = head, *p = pre->next;
    Date * before = (Date*)malloc (sizeof (Date));
    if (before == NULL) {
        cerr << "申请内存空间失败" << endl;
        return;
    }
    before->year = today->year;
    before->month = today->month;
    before->day = today->day;
    before->next = NULL;
    int days = CountDays (before);
    while (CountDays (p) <= days) {
        pre = p;
        p = p->next;
    }
    pre->next = before;
    before->next = p;
}

void SaveToFile (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    ofstream fout ("Data.dat");
    if (fout.fail ()) {
        cerr << "创建/写入文件失败！" << endl;
        return;
    }
    Date * p = head->next;
    int i = 0;
    while (p != NULL) {
        fout << p->year << '.' << ((p->month < 10) ? "0" : "") << p->month << '.' << ((p->day < 10) ? "0" : "") << p->day << "  ";
        p = p->next;
        if (++i % 6 == 0) {
            fout << endl;
        }
    }
    fout.close ();
    cout << "已保存至Date.dat" << endl;
}
void ShowListFile (Date * head)
{
    ifstream fin ("Data.dat");
    if (fin.fail ()) {
        cerr << "打开文件错误/文件尚未生成！" << endl;
        return;
    }
    system ("cls");
    char str[LINE_LENGTH];
    int line = 0;
    while (fin.getline (str, LINE_LENGTH)) {
        cout << setw (5) << ++line << ": " << str << endl;
        if (line % PAGE_LINE == 0) {
            cout << "按任意键显示下一页..." << endl;
            system ("pause>nul");
        }
    }
    fin.close ();
}

void ReverseList (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    Date * pre, *cur, *next;
    pre = NULL;
    cur = head->next;
    next = cur->next;
    while (cur != NULL) {
        cur->next = pre;
        pre = cur;
        cur = next;
        if (next != NULL) {
            next = cur->next;
        }
    }
    head->next = pre;
    cout << "链表反转完成！" << endl;
}

void HideCursor ()
{
    HANDLE hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo (hOut, &cci);
    cci.bVisible = false;
    SetConsoleCursorInfo (hOut, &cci);
}
void ShowCursor ()
{
    HANDLE hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo (hOut, &cci);
    cci.bVisible = true;
    SetConsoleCursorInfo (hOut, &cci);
}
void Swap (Date * a, Date * b)
{
    Date * tmp = (Date *)malloc (sizeof (Date));
    if (tmp == NULL) {
        cerr << "申请内存空间失败" << endl;
        return;
    }
    tmp->year = a->year;
    tmp->month = a->month;
    tmp->day = a->day;
    a->year = b->year;
    a->month = b->month;
    a->day = b->day;
    b->year = tmp->year;
    b->month = tmp->month;
    b->day = tmp->day;
}
void Sort (Date * head)
{
    if (IsEmptyLink (head)) {
        return;
    }
    int times = 0;
    cout << "正在排序......";
    HideCursor ();
    int nodeNum = NodeNum (head);
    Date * a, *b;
    for (int sortedNum = 0; sortedNum < nodeNum - 1; ++sortedNum) {
        cout << setw (3) << round ((double)times++ / nodeNum * 100) << '%';
        a = head->next;
        b = a->next;
        for (int i = 0; i < nodeNum - sortedNum - 1; ++i) {
            if (CountDays (a) > CountDays (b)) {
                Swap (a, b);
            }
            a = b;
            b = b->next;
        }
        cout << "\b\b\b\b";
    }
    ShowCursor ();
    cout << endl << "排序完成！" << endl;
}

void FreeList (Date * head)
{
    Date * pre = head->next, *next;
    if (pre != NULL) {
        next = pre->next;
        while (next != NULL) {
            free (pre);
            pre = next;
            next = pre->next;
        }
        free (pre);
    }
    head->next = NULL;
    cout << "已清空链表！" << endl;
}

bool IsReapYear (int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ? true : false);
}
bool IsIllegalDate (Date * p)
{
    if (IsReapYear (p->year) && p->month == 2) {
        return (p->day > 29 ? true : false);
    }
    else {
        return (p->day > dayOfMonth[p->month - 1] ? true : false);
    }
}
bool IsPrimeNumber (int n)
{
    if (n == 1 || n == 2) {
        return false;
    }
    for (int i = 2; i <= sqrt (n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool IsEmptyLink (Date * head)
{
    if (head->next == NULL) {
        cout << "链表为空，是否建立链表？(y/n)：" << endl;
        if (GetOptionYN ()) {
            CreateListRandom (head);
        }
        else {
            cout << "无法对空链表操作！" << endl;
            return true;
        }
    }
    return false;
}

int NodeNum (Date * head)
{
    int totalNum = 1;
    Date * p;
    p = head->next;
    if (p == NULL) {
        return 0;
    }
    while (p->next != NULL) {
        totalNum += 1;
        p = p->next;
    }
    return totalNum;
}
