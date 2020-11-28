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

tree_c *create_tree_node_c(const char *node)
{
    tree_c *present_node = NULL;
    present_node = (tree_c *)malloc(sizeof(tree_c));
    present_node->node = (char *)malloc(sizeof(char));
    memcpy(present_node->node, node, sizeof(char));
    present_node->parent = NULL;
    present_node->child_number = 0;
    present_node->child = NULL;
    return present_node;
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

tree_c *create_child_c(tree_c *const parent, const char *node)
{
    tree_c *child_tree = NULL;
    child_tree = create_tree_node_c(node);
    child_tree->parent = parent;
    parent->child_number++;
    if (parent->child != NULL)
    {
        parent->child = (tree_c *)realloc(parent->child, parent->child_number * sizeof(tree_c));
    }
    else
    {
        parent->child = (tree_c *)malloc(sizeof(tree_c));
    }
    parent->child[parent->child_number - 1] = *child_tree;
    // memccpy(parent->child + parent->child_number - 1, child_tree, 0, sizeof(tree_c));
    free(child_tree);
    child_tree = NULL;
    return parent->child + parent->child_number - 1;
}

void create_all_sort_tree_c(tree_c *root, const char *data, int deep, int end)
{

    if (deep >= end)
    {
        tree_c *tmp;
        tmp = root;
        while (tmp != NULL)
        {
            printf("-%d", tmp->node);
            printf("-%c", *tmp->node);
            tmp = tmp->parent;
        }
        printf("\n");
        return;
    }

    for (size_t i = 0; i < end; i++)
    {
        tree_c *present = NULL;
        present = create_child_c(root, &data[i]);
        create_all_sort_tree_c(&root->child[i], data, deep + 1, end);
    }

    // while (deep < end)
    // {
    //    tree *present = create_child(root,data,1);
    //    create_all_sort_tree(present,data,deep+1,end);
    // }
}

/**
 * 创建全排序树，广度优先
 * 
 * */
void create_all_sort_tree_BF_c(tree_c *root, const char *data, int deep, int end)
{
    if (deep >= end)
    {
        return;
    }
    for (size_t i = 0; i < end; i++)
    {
        create_child_c(root, &data[i]);
    }
    for (size_t j = 0; j < root->child_number; j++)
    {
        create_all_sort_tree_BF_c(&root->child[j], data, deep + 1, end);
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

void out_tree_c(tree_c *root)
{
    // LOGD("%c", *root->node);
    // printf("%c",*root->node);
    if (root->child_number == 0)
    {
        tree_c *tmp;
        tmp = root;
        while (tmp != NULL)
        {
            // printf("-%d", tmp->node);
            printf("\t%c", *tmp->node);
            tmp = tmp->parent;
        }
        printf("\n");

        return;
    }
    else
    {
        for (size_t i = 0; i < root->child_number; i++)
        {
            out_tree_c(root->child + i);
        }
    }
}

/***
 * 
 * 深度优先输出树
 * 
 * */
void out_tree_depth_first_c(tree_c *root)
{
    // printf("%c", *root->node);
    while (root->child_number == 0)
    {
        tree_c *tmp;
        tmp = root;
        while (tmp != NULL)
        {
            // printf("-%d", tmp->node);
            printf("\t%c", *tmp->node);
            tmp = tmp->parent;
        }
        printf("\n");
        return;
    }

    for (size_t i = 0; i < root->child_number; i++)
    {
        out_tree_depth_first_c(&root->child[i]);
    }
}