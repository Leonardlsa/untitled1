//
// Created by Leonard on 2022/11/23.
//
#include "basic_function.h"
#include "administrator.h"
#include "basic_struct.h"
#include "file_dealer.h"
#include <regex>

Goods *goodslist;
Order *orderlist;
int goods_num = 0;
int order_num = 0;

void show_all_goods() {
    if (!goods_num) {
        cout << "��ǰû���κ���Ʒ" << endl;
        return;
    }

    show_goods_prefix();

    for (int i = 0; i < goods_num; ++i) {
        goodslist[i].show();
    }
    cout << bar << endl;

    return;
}

void show_all_order() {
    if (!order_num) {
        cout << "��ǰû���κζ���" << endl;
        return;
    }

    show_order_prefix();
    for (int i = 0; i < order_num; ++i) {
        orderlist[i].show();
    }
    cout << bar3 << endl;
    return;
}

void search_goods() {
    cout << "��������Ʒ����:";
    string match;
    cin >> match;

    bool found = false;
    for (int i = 0; i < goods_num; ++i) {
        if (strstr(goodslist[i].name.c_str(), match.c_str()) != NULL) {
            if (!found) {
                show_goods_prefix();
            }
            goodslist[i].show();
            found = true;
        }
    }
    if (!found)print_message("û���ҵ�����Ҫ����Ʒ�����س�ʼ����");
    else show_goods_suffix();
}

void delaunch() {
    string id;
    cout << "������Ҫ�¼ܵ���ƷID:";
    cin >> id;
    cout << "ȷ��Ҫ�¼ܸ���Ʒ��?" << endl;
    bool found = false;
    for (int i = 0; i < goods_num; ++i) {
        if (strstr(goodslist[i].goodID.c_str(), id.c_str()) != NULL) {
            if (!found)show_goods_prefix();
            goodslist[i].show();
            show_goods_suffix();
            found = true;

            cout << "��ѡ��(y/n):";
            cin >> id;//����ʡ�ռ䣨bushi��id�˴�����choise
            if (id[0] == 'y' || id[0] == 'Y') {
                if (!goodslist[i].status)cout << "����Ʒ���¼�" << endl;
                else cout << "�¼ܳɹ�" << endl;
                goodslist[i].status = 0;
                goodslist[i].amount = 0;
            } else {
                cout << "ȡ���¼�" << endl;
            }
            break;
        }
    }
    if (!found)print_message("û���ҵ�����ƷŶ��");
}

void administrator_homepage() {
    goodslist = read_goods(goods_num);//׼����Ʒ�б�
    orderlist = read_order(order_num);
    string function[] = {"�鿴������Ʒ", "������Ʒ", "�¼���Ʒ", "�鿴���ж���", "�鿴�����û�", "����û�", "ע��"};

    loop_admin_hm_pg:
    clear();
    print(function, 7);

    int choise;
    cout << "���������:";
    cin >> choise;

    switch (choise) {
        case 1: {
            show_all_goods();
            getch();
            break;
        }

        case 2: {
            search_goods();
            getch();
            break;

        }
        case 3: {
            delaunch();
            getch();
            break;

        }
        case 4: {
            show_all_order();
            getch();
            break;
        }
        case 7: {
            cout << "���ڱ���༭..." << endl;
            write_goods(goodslist, goods_num);
            write_order(orderlist, order_num);
            cout << "�ټ�������ע��..." << endl;
            delete[] goodslist;
            getch();
            clear();
            return;
        }
        default: {
            err_input();
            goto loop_admin_hm_pg;
        }
    }
    goto loop_admin_hm_pg;

}