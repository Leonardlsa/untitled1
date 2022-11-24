//
// Created by 23221 on 2022/11/23.
//
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
#ifndef BIGPROJECT_BASIC_FUNCTION_H
#define BIGPROJECT_BASIC_FUNCTION_H

void clear();
void print(string *, int);
void print_message(string s);
void show_goods_prefix() ;
void show_goods_suffix();
void show_order_prefix() ;
void show_order_suffix() ;

    bool CheckPassWord(string password);
void err_input(string error_message="");
void COLOR_PRINT(const char* s, int color);


#endif //BIGPROJECT_BASIC_FUNCTION_H
