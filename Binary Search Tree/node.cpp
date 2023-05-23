#include "node.h"

Node::Node() : lchild{nullptr}, rchild{nullptr} {}
Node::~Node()
{
    delete this->lchild;
    delete this->rchild;
}