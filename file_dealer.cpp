//
// Created by Leonard on 2022/11/23.
//
#include "basic_struct.h"
#include "file_dealer.h"
#include <fstream>
#include <iostream>

const int MAX_GOODS = 100;
const int MAX_ORDER = 200;

/*
 * 管理员读取商品
 * item_number物品数
 */
Goods *read_goods(int &item_number) {
    std::ifstream fin;
    fin.open(GOODS_PATH);
    Goods temp;
    Goods *list = new Goods[MAX_GOODS];
    item_number = 0;
    while (fin >> temp.goodID) {
        fin >> temp.name
            >> temp.price
            >> temp.launch_time
            >> temp.sellerID
            >> temp.amount
            >> temp.status;
        list[item_number++] = temp;
    }
    return list;

}

bool write_goods(Goods *list, const int item_number) {
    std::ofstream fout;
    fout.open(GOODS_PATH);
    if (!fout.is_open()) {
        std::cout << "存储文件意外无法打开" << std::endl;
        return false;
    }
    for (int i = 0; i < item_number; ++i) {
        fout << list[i].goodID << '\t'
             << list[i].name << '\t'
             << list[i].price << '\t'
             << list[i].launch_time << '\t'
             << list[i].sellerID << '\t'
             << list[i].amount << '\t'
             << list[i].status << std::endl;
    }
    return true;
}

Order *read_order(int &item_number) {
    std::ifstream fin;
    fin.open(ORDER_PATH);
    Order temp;
    Order *list = new Order[MAX_GOODS];
    item_number = 0;
    while (fin >> temp.orderID) {
        fin >> temp.goodID
            >> temp.transaction_price
            >> temp.amount
            >> temp.transaction_time
            >> temp.sellerID
            >> temp.buyerID;
        list[item_number++] = temp;
    }
    return list;

}

bool write_order(Order *list, const int item_number) {
    std::ofstream fout;
    fout.open(ORDER_PATH);
    if (!fout.is_open()) {
        std::cout << "存储文件意外无法打开" << std::endl;
        return false;
    }
    for (int i = 0; i < item_number; ++i) {
        fout << list[i].orderID << '\t'
             << list[i].goodID << '\t'
             << list[i].transaction_price << '\t'
             << list[i].amount << '\t'
             << list[i].transaction_time << '\t'
             << list[i].sellerID << '\t'
             << list[i].buyerID << std::endl;
    }
    return true;
}