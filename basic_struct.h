//
// Created by Leonard on 2022/11/23.
//

#ifndef BIGPROJECT_BASIC_STRUCT_H
#define BIGPROJECT_BASIC_STRUCT_H

#include <string>

using std::string;
const static char* GOODS_PATH=".\\data\\goods.txt";
const static char* ORDER_PATH=".\\data\\order.txt";
const int goodShow[]={9,15,8,15,9,8,12};
const int orderShow[]={9,9,9,8,15,9,9};
static std::string bar(75, '*');
static std::string bar3(60, '*');
struct Goods{
    string goodID;
    string name;
    float price;
    string launch_time;
    string sellerID;
    int amount;
    int status;//0代表已下架，1代表销售中,2代表补货中
    void show();
};

struct Order{
    string orderID;
    string goodID;
    float transaction_price;
    int amount;
    string transaction_time;
    string sellerID;
    string buyerID;
    void show();
};
#endif //BIGPROJECT_BASIC_STRUCT_H
