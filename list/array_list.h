//
// Created by link on 2019-03-12.
//

#ifndef DATASTRACK_ARRAY_LIST_H
#define DATASTRACK_ARRAY_LIST_H


#include "list.h"

class array_list : virtual public list{

private:
    int *data;
    int length;



public:
    array_list(int *data, int length);
    ~array_list();

public:

    void insertSort();
    void printAll();
    int say_hello();
};


#endif //DATASTRACK_ARRAY_LIST_H
