#ifndef BINARY_TREE
#define BINARY_TREE
#include "node.h"
#include <vector>

class BinaryTree
{
public:
    Node *root; // to avoid getters & setters root is public but normally must be private
    void generate_bst(std::vector<int> numbers);
    void insert(Node *t, int key);
    void preorder_traversal(Node *t);
    void inorder_traversal(Node *t);
    void postorder_traversal(Node *t);
    Node *recursive_insert(Node *p, int key);
    Node *recursive_search(Node *t, int key);
    Node *recursive_delete(Node *p, int key);
    int find_height(Node *p);
    Node *in_pre(Node *p);
    Node *in_suc(Node *p);
    BinaryTree(/* args */);
    ~BinaryTree();
};

#endif