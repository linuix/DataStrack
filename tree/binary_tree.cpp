#include "binary_tree.h"

void _add_child_node(p_binary_tree root, char node)
{
    if (root->l_child == nullptr)
    {
        p_binary_tree next_node = (p_binary_tree)malloc(sizeof(binary_tree));
        
    }
}

p_binary_tree create_compare_binary_tree(char *data, int size)
{
    p_binary_tree root = (p_binary_tree)malloc(sizeof(binary_tree));
    memset(root, 0, sizeof(binary_tree));
    root->node = "root";
    p_binary_tree current_node = root;
    for (int i = 0; i < size; i++)
    {
        _add_child_node(current_node, data[i]);
    }
}
void out_binary_tree(p_binary_tree root)
{
}

void free_binary_tree(p_binary_tree root)
{
}