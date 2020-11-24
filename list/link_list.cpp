//
// Created by link on 2019-03-10.
//

#include "link_list.h"




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



link_list::link_list() {
    data_array = (int*)malloc(DEFAULT_LENGTH*sizeof(int));
}


