#ifndef TREE
#define TREE
#include "node.h"
#include "queue.h"

class Tree
{
public:
    Node *root;
    Tree();
    void create_tree();
    void preorder(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    // void level_order(Node *p);
    int height(Node *root);
};

#endif