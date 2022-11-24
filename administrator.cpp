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
        cout << "当前没有任何商品" << endl;
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
        cout << "当前没有任何订单" << endl;
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
    cout << "请输入商品名称:";
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
    if (!found)print_message("没有找到你想要的商品！返回初始界面");
    else show_goods_suffix();
}

void delaunch() {
    string id;
    cout << "请输入要下架的商品ID:";
    cin >> id;
    cout << "确认要下架该商品吗?" << endl;
    bool found = false;
    for (int i = 0; i < goods_num; ++i) {
        if (strstr(goodslist[i].goodID.c_str(), id.c_str()) != NULL) {
            if (!found)show_goods_prefix();
            goodslist[i].show();
            show_goods_suffix();
            found = true;

            cout << "请选择(y/n):";
            cin >> id;//重用省空间（bushi，id此处代表choise
            if (id[0] == 'y' || id[0] == 'Y') {
                if (!goodslist[i].status)cout << "该商品已下架" << endl;
                else cout << "下架成功" << endl;
                goodslist[i].status = 0;
                goodslist[i].amount = 0;
            } else {
                cout << "取消下架" << endl;
            }
            break;
        }
    }
    if (!found)print_message("没有找到该商品哦！");
}

void administrator_homepage() {
    goodslist = read_goods(goods_num);//准备商品列表
    orderlist = read_order(order_num);
    string function[] = {"查看所有商品", "搜索商品", "下架商品", "查看所有订单", "查看所有用户", "封禁用户", "注销"};

    loop_admin_hm_pg:
    clear();
    print(function, 7);

    int choise;
    cout << "请输入操作:";
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
            cout << "正在保存编辑..." << endl;
            write_goods(goodslist, goods_num);
            write_order(orderlist, order_num);
            cout << "再见，正在注销..." << endl;
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