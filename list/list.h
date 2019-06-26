//
// Created by link on 2019-04-20.
//

#ifndef DATASTRACK_LIST_H
#define DATASTRACK_LIST_H

#include "stdio.h"

class list {
protected:
    struct item{
       int data;
       item *next;
    };
public:
    list();

    virtual ~list();

    virtual int say_hello();

};


#endif //DATASTRACK_LIST_H
