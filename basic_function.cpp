#include "basic_function.h"
#include "basic_struct.h"

using std::string;
using std::cout;

/*��ӡ��Ŀ
 * s�����ӡ��Ŀ
 * num����Ŀ����
 */
inline void clear() { system("cls"); }

void print(string *s, int num) {
    string out;
    for (int i = 0; i < num; ++i) {
        out += (char) (i + 49);
        out += ".";
        out += s[i];
        out += '\t';
    }
    int len = (int) out.length();

    string bar2((int) (len * 1.35), '=');
    cout << bar2 << std::endl
         << out << std::endl
         << bar2 << std::endl << std::endl;
}

void print_message(string s) {
    string bar2((int) (s.length() * 1.35), '*');
    cout << bar << std::endl
         << s << std::endl
         << bar << std::endl << std::endl;
}

/*
 * prefixչʾ��Ʒ��ͷ
 * suffixչʾ��Ʒ��β
 */
void show_goods_prefix() {
    cout << bar << endl
         << std::setw(goodShow[0]) << std::left << "��ƷID"
         << std::setw(goodShow[1]) << std::left << "����"
         << std::setw(goodShow[2]) << std::left << "�۸�"
         << std::setw(goodShow[3]) << std::left << "�ϼ�ʱ��"
         << std::setw(goodShow[4]) << std::left << "����ID"
         << std::setw(goodShow[5]) << std::left << "����"
         << std::setw(goodShow[6]) << std::left << "��Ʒ״̬" << endl;
}

void show_goods_suffix() {
    cout << bar << endl;
}

void show_order_prefix() {
    std::cout << std::setw(orderShow[0]) << std::left << "����ID"
              << std::setw(orderShow[1]) << std::left << "��ƷID"
              << std::setw(orderShow[2]) << std::left << "���׵���"
              << std::setw(orderShow[3]) << std::left << "����"
              << std::setw(orderShow[4]) << std::left << "����ʱ��"
              << std::setw(orderShow[5]) << std::left << "����ID"
              << std::setw(orderShow[6]) << std::left << "���ID" << endl;
}
void show_order_suffix() {
    cout << bar3 << endl;
}

/*
 * ��"*"�������룬���λ���
 * password��������
 * cursor�����ָ
 * judge��������Դ�
 */
bool CheckPassWord(string password) {
    bool judge = false;
    int cursor;
    int remaintimes = 1;
    string s;
    char temp;
    char truepassword[50];
    while (remaintimes <= 3) {
        cursor = 0;
        while ((temp = getch()) != '\r') {
            if (temp == '\b' && cursor > 0) {
                printf("\b \b");
                cursor--;
            } else {
                truepassword[cursor++] = temp;
                cout << '*';
            }
        }
        truepassword[cursor] = '\0';
        cout << endl;
        if (password.compare(truepassword) != 0) {
            if (remaintimes == 3)
                cout << "��������˳���" << endl << endl;
            else
                cout << "�������ʣ��" << (3 - remaintimes) << "�λ��᣺";
            remaintimes++;
        } else {
            judge = true;
            return judge;
        }
    }
    if (remaintimes == 4)
        return judge;
    return judge;
}

void err_input(string error_message) {
    cout << "���벻��Ҫ������������" << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getch();
    clear();
}

void COLOR_PRINT(const char *s, int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf(s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

