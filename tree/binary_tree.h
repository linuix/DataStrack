#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree
{
    binary_tree *l_child;
    binary_tree *r_child;
    char *node;
} * p_binary_tree;

p_binary_tree create_compare_binary_tree(char *data, int size);
void out_binary_tree(p_binary_tree root);
void free_binary_tree(p_binary_tree root);