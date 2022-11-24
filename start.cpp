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
    if (_access(prefix.c_str(), 0) == -1)    //����ļ��в�����
    {
        _mkdir(prefix.c_str());
        ftouch.open(GOODS_PATH);
        ftouch.open(ORDER_PATH);
    }
}

void login_surface() {
    initialize();
    string login_choice[NUM_LOGIN_CHOICE] =
            {"����Ա��¼",
             "�û�ע��",
             "�û���¼",
             "�˳�����"};

    login_loop:
    print(login_choice, NUM_LOGIN_CHOICE);

    int choice;//����ѡ��
    cout << "�������:";
    cin >> choice;

    switch (choice) {
        case 1: {

            // ����Ա��¼
            string admin, pass;
            cout << "���������Ա����:";
            cin >> admin;
            getchar();
            cout << "����������:" << std::flush;
            string p = "123456";//Ӳ���룬Σ��
            if (CheckPassWord(p) && admin == "admin") {
                cout << "-----��¼�ɹ�-----" << endl << endl;
                administrator_homepage();//����Ա�������
            } else {
                cout << "----�˺Ż�������󣬵�¼ʧ�ܣ��������˵�----" << endl << endl;
                getch();
                clear();
            }
            break;
        }
        case 4: {
            cout << "=========��л���ʹ�ã��ټ�==========" << endl;
            return;
        }
        default: {
            err_input();
        }
    }
    goto login_loop;
}
