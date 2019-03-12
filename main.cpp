#include <iostream>
#include "list/link_list.h"


int main() {
    std::cout << "--------------start---------------" << std::endl;
    link_list link_list1;
    link_list1.simple_sort();
//    link_list1.out_print();
    std::cout << "--------------end---------------" << std::endl;
    return 0;
}