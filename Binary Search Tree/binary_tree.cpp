#include "binary_tree.h"
#include "node.h"
#include <vector>
#include <iostream>

BinaryTree::BinaryTree() : root{nullptr}
{
}

BinaryTree::~BinaryTree()
{
    delete this->root;
}

void BinaryTree::generate_bst(std::vector<int> numbers)
{
    for (int num : numbers)
    {
        root = recursive_insert(root, num);
    }
}

void BinaryTree::preorder_traversal(Node *t)
{
    if (t != nullptr)
    {
        std::cout << t->data << " ";
        preorder_traversal(t->lchild);
        preorder_traversal(t->rchild);
    }
}

void BinaryTree::inorder_traversal(Node *t)
{
    if (t != nullptr)
    {
        inorder_traversal(t->lchild);
        std::cout << t->data << " ";
        inorder_traversal(t->rchild);
    }
}

void BinaryTree::postorder_traversal(Node *t)
{
    if (t != nullptr)
    {
        postorder_traversal(t->lchild);
        postorder_traversal(t->rchild);
        std::cout << t->data << " ";
    }
}

Node *BinaryTree::recursive_search(Node *t, int key)
{
    if (t == nullptr) // binary tree doesn't exist
    {
        return nullptr;
    }
    if (key == t->data) // if key is found return the node
    {
        return t;
    }
    else if (key < t->data) // if key < t->data then search left side of the root
    {
        return recursive_search(t->lchild, key);
    }
    else // key > t->data then search right side of the root
    {
        return recursive_search(t->rchild, key);
    }
}

Node *BinaryTree::recursive_insert(Node *p, int key)
{
    Node *t{nullptr};

    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = recursive_insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = recursive_insert(p->rchild, key);
    }

    return p;
}

void BinaryTree::insert(Node *t, int key)
{
    Node *r{nullptr};
    Node *p{nullptr};

    while (t != nullptr)
    {
        r = t;
        if (key == t->data)
        {
            return; // key is found before cannot duplicate it finish function
        }
        else if (key < t->data)
        {
            t = t->lchild; // if left child is nullptr r will be the previous and t will be nullptr while ends
        }
        else
        {
            t = t->rchild; // if right child is nullptr r will be the previous node and t will be nullptr (while ends)
        }
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;

    if (p->data < r->data)
    {
        r->lchild = p;
    }
    else if (p->data > r->data)
    {
        r->rchild = p;
    }
}