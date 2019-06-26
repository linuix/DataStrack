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

    /**
     * 简单插入排序
     */
    void insertSort();
    void insertSort2();
    void printAll();
    int say_hello();

public:
    void move(int start, int end, int offset);
};


#endif //DATASTRACK_ARRAY_LIST_H
