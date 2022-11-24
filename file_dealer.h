//
// Created by Leonard on 2022/11/23.
//

#ifndef BIGPROJECT_FILE_DEALER_H
#define BIGPROJECT_FILE_DEALER_H
Goods* read_goods(int &item_number);
bool write_goods(Goods *list, const int item_number);
Order *read_order(int &item_number) ;
bool write_order(Order *list, const int item_number);

#endif //BIGPROJECT_FILE_DEALER_H
