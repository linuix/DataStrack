//
// Created by link on 2019-03-10.
//

#ifndef DATASTRACK_SORT_LIST_H
#define DATASTRACK_SORT_LIST_H
#include <log_util.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "tree/tree.h"

#define NUMBER 26

 void all_sort_number(int data[], int length);

void out_data(int data[], int length);
void all_sort(int start,int end,int data[]);
void swap(int i1, int i2,int data[]);
void sort_byte(int data[], int start, int end);
void conver(int data[], int start);
void sort_a_z();
void out_a_z(int data);
void all_sort_tree(int start, int end, int data[]);



class Sorter
{
private:
    /* data */

public:
    Sorter();
    ~Sorter();

public:
    // template <class T>
    // void all_sort(T *d, int length);
};

#endif //DATASTRACK_SORT_LIST_H
