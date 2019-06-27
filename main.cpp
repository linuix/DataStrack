#include <iostream>
#include "list/array_list.h"


int main() {

    int a[] = {3,4,6,30,1,2,10,8};

    array_list *l1;
    l1 = new array_list(a,8);
    l1->binSort();
    l1->printAll();
    return 0;
}