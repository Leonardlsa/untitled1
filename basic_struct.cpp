//
// Created by 23221 on 2022/11/23.
//
#include "basic_function.h"
#include "basic_struct.h"

void Goods::show() {
    std::cout << std::setw(goodShow[0]) << std::left << goodID
              << std::setw(goodShow[1]) << std::left << name
              << std::setw(goodShow[2]) << std::left << price
              << std::setw(goodShow[3]) << std::left << launch_time
              << std::setw(goodShow[4]) << std::left << sellerID
              << std::setw(goodShow[5]) << std::left << amount;
    if (status == 1) std::cout << std::setw(goodShow[6]) << std::left << "销售中";
    else if (status == 0)std::cout << std::setw(goodShow[6]) << std::left << "已下架";
    else std::cout << std::setw(goodShow[6]) << std::left << "补货中";
    cout << endl;
}

void Order::show() {
    std::cout << std::setw(orderShow[0]) << std::left << orderID
              << std::setw(orderShow[1]) << std::left << goodID
              << std::setw(orderShow[2]) << std::left << transaction_price
              << std::setw(orderShow[3]) << std::left << amount
              << std::setw(orderShow[4]) << std::left << transaction_time
              << std::setw(orderShow[5]) << std::left << sellerID
              << std::setw(orderShow[6]) << std::left << buyerID << endl;
}