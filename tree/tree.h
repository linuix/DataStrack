#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log_util.h"

struct tree
{
    tree *child; //字节点采用的数据存储
    int child_number;
    tree *parent;
    char *node;
};

tree *create_root_tree(const char *node, int length);

tree *create_child(tree *t,const char *node, int length);

void out_tree(tree *root);
