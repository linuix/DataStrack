#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <string.h>

int main(char *args[], int argv)
{
    int data[] = {1, 2, 3, 4, 5, 6};

    tree_c *root = create_tree_node_c("");
    char data_c[3] = {'a', 'b', 'c'};
    // create_child(root, "child1", 6);
    // create_child(root, "child2", 6);
    // create_child(create_child(root, "child3", 6), "child4", 6);

    create_all_sort_tree_BF_c(root, data_c, 0, sizeof(data_c));

    out_tree_c(root);
    LOGD("---------------------------------------------");
    out_tree_depth_first_c(root);

    return 0;
}
