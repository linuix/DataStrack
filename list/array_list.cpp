//
// Created by link on 2019-03-12.
//
#include<string.h>
#include "array_list.h"
#include "log_util.h"

array_list::array_list(int *data, int length)
{
    LOGD("array_list constructor");
    this->data = data;
    this->length = length;
}

array_list::~array_list() {
    LOGD("array_list destructor");
    delete data;
}

void array_list::firstSort(){
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i+1; j < length; j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    
}




int array_list::say_hello() {
    LOGD("array_list say_hello");
}

void array_list::printAll() {
    for (int i = 0; i < length; i++) {
        LOGD("%d\t",data[i]);
    }
}

void array_list::insertSort() {
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            int temp = data[i];
            if (temp<data[j]){
                move(j,i-1,1);
                data[j] = temp;
            }
        }
    }

}

void array_list::move(int start, int end, int offset) {
    int i;
    if (offset>0){
        i = end;
    } else if (offset<0){
        i = start;
    } else {
        return;
    }

    for (;offset >= 0?i >= start:i<=end; offset>0?i--:i++) {
        data[i+offset] = data[i];
    }

}

void array_list::binSort() {

    for (int i = 2; i < length; ++i) {
        int start = 0,end = i-1;
        int mid;
        while (start <= end) {
            mid = (end+start)/2;
            if (data[i] < data[mid]){
                end = mid-1;
            } else if (data[i] > data[mid]){
                start = mid+1;
            }else{
                break;
            }

        }
        if (start >= i){
            continue;
        }
        int tmp = data[i];
        move(mid,i-1,1);
        data[mid] = tmp;
    }

}


