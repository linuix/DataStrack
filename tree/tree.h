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

tree *create_root_tree(const char *node, int length);

/**
 * 创建节点
 * 
 * */
tree *create_child(tree *t,const char *node, int length);

void out_tree(tree *root);


#endif
