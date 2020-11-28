#include "list/array_list.h"
#include "sort/sort_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree/tree.h"
#include <string.h>

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    // array_list *l1;
    // l1 = new array_list(a,8);
    // l1->binSort();
    // l1->printAll();

    // Sorter::all_sort(a,5);
    // Sorter *s = new Sorter();
    // all_sort(0,sizeof(data)/sizeof(int),data);

    // all_sort(a,4);

    // int data1[2];
    // memset(data1, 0, sizeof(data1) / sizeof(int));
    // sort_byte(data1, 0, sizeof(data1) / sizeof(int));\

    // sort_a_z();

    tree_c *root = create_tree_node_c("");
    char data_c[3] = {'a','b','c'};
    // create_child(root, "child1", 6);
    // create_child(root, "child2", 6);
    // create_child(create_child(root, "child3", 6), "child4", 6);

    create_all_sort_tree_BF_c(root, data_c, 0, sizeof(data_c));

    out_tree_c(root);
    LOGD("---------------------------------------------");
    out_tree_depth_first_c(root);

    return 0;
}
