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
     * 快速排序
     */
    void firstSort();
    /**
     * 插入排序
     */
    void insertSort();
    /**
     * 折半插入排序
     */
     void binSort();
    void printAll();
    int say_hello();

public:
    void move(int start, int end, int offset);
};


#endif //DATASTRACK_ARRAY_LIST_H
