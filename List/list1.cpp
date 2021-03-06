#include "list.h"

using namespace std;
int main()
{
    Date * head = InitList ();

    while (1) {
        ShowCopyright ();
        ShowTime ();
        if (head == NULL) {
            cerr << "程序异常：申请内存空间失败，请重启程序！" << endl;
            exit (-1);
        }
        cout << "当前节点数量：" << NodeNum (head) << endl;
        UserInterface ();
        char keyPress = GetOption (head);
        switch (keyPress)
        {
        case 'C':CreateListRandom (head); break;
        case 'O':PrintList (head); break;
        case 'D':DeleteNode (head); break;
        case 'N':ShowIllegalNode (head); break;
        case 'T':ShowTotalDays (head); break;
        case 'P':PrimeNumberNode (head); break;
        case 'I':Insert (head); break;
        case 'S':SaveToFile (head); break;
        case 'X':ShowListFile (head); break;
        case 'F':ReverseList (head); break;
        case 'A':Sort (head); break;
        case 'Z':FreeList (head); break;
        default:cout << "选择错误，请重新选择......" << endl; break;
        }
        cout << endl;
        system ("pause");
        system ("cls");
    }
        
    return 0;
}
