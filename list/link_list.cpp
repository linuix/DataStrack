//
// Created by link on 2019-03-10.
//

#include "link_list.h"

void link_list::simple_sort() {
    int sort_array[9];
    for (int i = 0; i < 9; ++i)
    {
        int max = seek_max(data_array,9,i+1);
        sort_array[i] = max;
    }
    for (int j = 0; j < 9;  j++) {
        cout<<sort_array[j]<<"\t";
    }
    cout<<endl;
}



int link_list::seek_max(int *data_array, int length, int sort_index){
    int max = data_array[0];
    for (int i=0;i<length;i++){
        if (max < data_array[i]){
            int temp = max;
            max = data_array[i];
            data_array[i] = temp;
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


