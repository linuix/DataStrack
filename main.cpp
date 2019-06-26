#include <iostream>
#include "list/array_list.h"


int main() {

    int a[] = {3,4,6,30,1,2};

    array_list *l1;
    l1 = new array_list(a,6);
    l1->insertSort();
    l1->printAll();
    return 0;
}