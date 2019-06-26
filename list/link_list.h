//
// Created by link on 2019-03-10.
//

#ifndef DATASTRACK_LINK_LIST_H
#define DATASTRACK_LINK_LIST_H

#include "iostream"

using namespace std;

class link_list {
private:
    int *data_array;
    struct DataStruct{
        int a = 0;
        DataStruct *next;
    };
public:
    link_list();

    void out_print();

    int seek_max(int *data_array, int length, int sort_index);
};


#endif //DATASTRACK_LINK_LIST_H
