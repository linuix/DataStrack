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


