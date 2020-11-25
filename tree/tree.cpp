#include "tree.h"

tree *create_root_tree(const char *node, int length)
{
    tree *root = NULL;
    root = (tree *)malloc(sizeof(tree));
    root->node = (char *)malloc(length);
    memcpy(root->node, node, length);
    root->parent = NULL;
    root->child_number = 0;
    root->child = NULL;
    return root;
}

tree *create_child(tree *parent, const char *node, int length)
{
    tree *child_tree = NULL;
    child_tree = create_root_tree(node, length);
    child_tree->parent = parent;
    parent->child_number++;
    if (parent->child != NULL)
    {
        parent->child = (tree *)realloc(parent->child, parent->child_number * sizeof(tree));
    }
    else
    {
        parent->child = (tree *)malloc(sizeof(tree));
    }
    parent->child[parent->child_number - 1] = *child_tree;
    free(child_tree);

    return parent->child + parent->child_number - 1;
}

void create_tree(tree *root, char **data, int size, int length)
{
    if (size <= 0)
    {
        create_child(root,data[size],length);
    }
    
}

void out_tree(tree *root)
{
    LOGD("%s", root->node);
    if (root->child_number == 0)
    {
        return;
    }
    else
    {
        for (size_t i = 0; i < root->child_number; i++)
        {
            out_tree(root->child + i);
        }
    }
}