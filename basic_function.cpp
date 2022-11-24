#include "basic_function.h"
#include "basic_struct.h"

using std::string;
using std::cout;

/*打印条目
 * s：需打印条目
 * num：条目数量
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
 * prefix展示商品表头
 * suffix展示商品表尾
 */
void show_goods_prefix() {
    cout << bar << endl
         << std::setw(goodShow[0]) << std::left << "商品ID"
         << std::setw(goodShow[1]) << std::left << "名称"
         << std::setw(goodShow[2]) << std::left << "价格"
         << std::setw(goodShow[3]) << std::left << "上架时间"
         << std::setw(goodShow[4]) << std::left << "卖家ID"
         << std::setw(goodShow[5]) << std::left << "数量"
         << std::setw(goodShow[6]) << std::left << "商品状态" << endl;
}

void show_goods_suffix() {
    cout << bar << endl;
}

void show_order_prefix() {
    std::cout << std::setw(orderShow[0]) << std::left << "订单ID"
              << std::setw(orderShow[1]) << std::left << "商品ID"
              << std::setw(orderShow[2]) << std::left << "交易单价"
              << std::setw(orderShow[3]) << std::left << "数量"
              << std::setw(orderShow[4]) << std::left << "交易时间"
              << std::setw(orderShow[5]) << std::left << "卖家ID"
              << std::setw(orderShow[6]) << std::left << "买家ID" << endl;
}
void show_order_suffix() {
    cout << bar3 << endl;
}

/*
 * 以"*"输入密码，三次机会
 * password输入密码
 * cursor光标所指
 * judge代表密码对错
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
                cout << "密码错误，退出！" << endl << endl;
            else
                cout << "密码错误，剩余" << (3 - remaintimes) << "次机会：";
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
    cout << "输入不符要求，请重新输入" << endl;
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

