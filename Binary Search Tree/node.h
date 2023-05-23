#ifndef NODE
#define NODE

class Node
{
public:
    Node();
    ~Node();

    Node *lchild;
    Node *rchild;
    int data;
};

#endif