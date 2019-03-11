//
// Created by link on 2019-03-10.
//

#ifndef DATASTRACK_LINK_LIST_H
#define DATASTRACK_LINK_LIST_H

#include "iostream"

using namespace std;

class link_list {
private:
    int data_array[9]={1,2,5,3,4,7,6,8,9};
    struct DataStruct{
        int a = 0;
        DataStruct *next;
    };
public:
    void simple_sort();
    void out_print();

    int seek_max(int *data_array, int length, int sort_index);
    int move_array(int *data_array, int length,int sort_index, int start, int end);
};


#endif //DATASTRACK_LINK_LIST_H
