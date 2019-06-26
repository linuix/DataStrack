//
// Created by link on 2019-03-12.
//

#include "array_list.h"

array_list::array_list(int *data, int length)
{
    log("array_list constructor\n");
    this->data = data;
    this->length = length;
}

array_list::~array_list() {
    log("array_list destructor\n");
    delete data;
}

void array_list::insertSort(){
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
    log("array_list say_hello\n");
}

void array_list::printAll() {
    for (int i = 0; i < length; i++) {
        log("%d\t",data[i]);
    }
    log("\n");

}

void array_list::insertSort2() {
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

    for (;offset >= 0?i >= start:i<end; offset>0?i--:i++) {
        data[i+offset] = data[i];
    }

}


