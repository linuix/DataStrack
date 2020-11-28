#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log_util.h"

#ifndef __TOOLS_H__
#define __TOOLS_H__

struct tree
{
    tree *child; //字节点采用的数据存储
    int child_number;
    tree *parent;
    char *node;
};

struct tree_c
{
    tree_c *child = NULL; //字节点采用的数据存储
    int child_number = 0;
    tree_c *parent= NULL;
    char *node= NULL;
};

void create_all_sort_tree_BF_c(tree_c *root, const char *data, int deep, int end);

void create_all_sort_tree_c(tree_c *root, const char *data, int deep, int end);

tree *create_root_tree(const char *node, int length);
tree_c *create_tree_node_c(const char *node);

/**
 * 创建节点
 * 
 * */
tree *create_child(tree *t,const char *node, int length);
tree_c *create_child_c( tree_c * const parent, const char *node);

void out_tree_c(tree_c *root);
void out_tree(tree *root);
void out_tree_depth_first_c(tree_c *root);

#endif
