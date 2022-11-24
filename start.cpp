//
// Created by 23221 on 2022/11/23.
//

#include <string>
#include "basic_function.h"
#include "basic_struct.h"
#include "start.h"
#include "administrator.h"
#include <io.h>
#include <direct.h>
#include <fstream>

using std::string;

void initialize() {
    std::string prefix = "./data/";
    std::ofstream ftouch;
    if (_access(prefix.c_str(), 0) == -1)    //如果文件夹不存在
    {
        _mkdir(prefix.c_str());
        ftouch.open(GOODS_PATH);
        ftouch.open(ORDER_PATH);
    }
}

void login_surface() {
    initialize();
    string login_choice[NUM_LOGIN_CHOICE] =
            {"管理员登录",
             "用户注册",
             "用户登录",
             "退出程序"};

    login_loop:
    print(login_choice, NUM_LOGIN_CHOICE);

    int choice;//操作选择
    cout << "输入操作:";
    cin >> choice;

    switch (choice) {
        case 1: {

            // 管理员登录
            string admin, pass;
            cout << "请输入管理员姓名:";
            cin >> admin;
            getchar();
            cout << "请输入密码:" << std::flush;
            string p = "123456";//硬编码，危险
            if (CheckPassWord(p) && admin == "admin") {
                cout << "-----登录成功-----" << endl << endl;
                administrator_homepage();//管理员操作面板
            } else {
                cout << "----账号或密码错误，登录失败，返回主菜单----" << endl << endl;
                getch();
                clear();
            }
            break;
        }
        case 4: {
            cout << "=========感谢你的使用，再见==========" << endl;
            return;
        }
        default: {
            err_input();
        }
    }
    goto login_loop;
}
