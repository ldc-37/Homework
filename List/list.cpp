// Chain.cpp: 定义控制台应用程序的入口点。
//

#include "list.h"

using namespace std;
int main()
{
    while (1) {
        ShowCopyright ();
        ShowTime ();
        UserInterface ();
        char keyPress = GetOption ();
        switch (keyPress)
        {

            default:cout << "选择错误，请重新选择......" << endl; break;
        }
        system ("pause");
        system ("cls");
    }
        
    return 0;
}

void ShowCopyright ()
{
    cout << "Copyright (c) 2017-2018 李定成(221701331). All Rights Reserved." << endl;
}

void ShowTime ()
{
    time_t now = time (0);
    struct tm nowTime;
    localtime_s (&nowTime,&now);
    int hour = nowTime.tm_hour;
    int min = nowTime.tm_min;
    int sec = nowTime.tm_sec;
    int year = 1900 + nowTime.tm_year;
    int month = 1 + nowTime.tm_mon;
    int day = nowTime.tm_mday;
    int weekNum = nowTime.tm_wday;
    const char *weekChn[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    const char *week = weekChn[weekNum];

    cout << "当前日期、时间：" << year << '.' << month << '.' << day << '(' << week << ") " << hour << ':' << min << ':' << sec << endl;

}

void UserInterface ()
{
    cout << "****************************************************************" << endl <<
        "*    C:创建一个存放日期数据的 (无序)链表                       *" << endl <<
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
        "*    Q : 退出系统                                              *" << endl <<
        "****************************************************************" << endl <<
        "请选择 (C, O, S, X, N, D, I, T, A, P, F, Q) : ";
}

char GetOption ()
{
    char key;
    while (1) {
        if (_kbhit ()) {
            key = _getch ();
            if (key == 'q' || key == 'Q') {
                exit (0);
            }
            else if (key >='a' && key <= 'z' || key >= 'A' && key <= 'Z'){
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


