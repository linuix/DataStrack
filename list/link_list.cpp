//
// Created by link on 2019-03-10.
//

#include "link_list.h"

void link_list::simple_sort() {
    int temp = data_array[0];
    int sort_index = 0;
    for (int i = 1; i < 9; ++i)
    {
        int max = seek_max(data_array,9,sort_index);
        sort_index++;
        for (int j = 0; j <= sort_index; ++j) {
            
        }
    }
}



int link_list::seek_max(int *data_array, int length, int sort_index){
    int max = data_array[sort_index];
    for (int i=sort_index;i<length;i++){
        if (max <= data_array[i]){
            max = data_array[i];
        }
    }
    return max;

}

void link_list::out_print() {
    for (int i = 0; i < 9; ++i) {
        std::cout<<data_array[i]<<"\t";
    }
    cout<<endl;

}

int link_list::move_array(int *data_array, int length, int sort_index, int start, int end) {
    if(start<end){
        for (int i = end; i > start; i--) {
            data_array[i] = data_array[i-1];
        }
    }
    return 0;
}


