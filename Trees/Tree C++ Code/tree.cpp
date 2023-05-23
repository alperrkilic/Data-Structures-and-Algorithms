#include "tree.h"
#include "queue.h"

Tree::Tree()
{
    this->root = nullptr;
}

void Tree::create_tree()
{
    Node *p, *temp; // declaring 2 pointers for Node
    int x;
    Queue q(100); // 100 elements of queue array

    std::cout << "Enter root value: ";
    std::cin >> x;
    this->root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root); // push the root into queue

    while (!q.isEmpty())
    {
        p = q.dequeue();
        std::cout << "Enter left child of " << p->data << ": ";
        std::cin >> x;

        if (x != -1)
        {
            temp = new Node;
            temp->data = x;
            temp->lchild = temp->rchild = nullptr;
            p->lchild = temp;
            q.enqueue(temp);
        }

        std::cout << "Enter right child of " << p->data << ": ";
        std::cin >> x;

        if (x != -1)
        {
            temp = new Node;
            temp->data = x;
            temp->lchild = temp->rchild = nullptr;
            p->rchild = temp;
            q.enqueue(temp);
        }
    }
}

void Tree::preorder(Node *p) // root left right
{
    if (p)
    {
        std::cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p) // left root right
{
    if (p)
    {
        inorder(p->lchild);
        std::cout << p->data << " ";
        inorder(p->rchild);
    }
}

void Tree::postorder(Node *p) // left right root
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        std::cout << p->data << " ";
    }
}

void Tree::level_order(Node *p)
{
    Queue q;
    std::cout << p->data << " ";
    q.enqueue(p);

    while (q.isEmpty() != false)
    {
        p = q.dequeue();
        if (p->lchild != nullptr)
        {
            std::cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild != nullptr)
        {
            std::cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::height(Node *root)
{
    int x = 0, y = 0;

    if (root == nullptr)
    {
        return 0;
    }

    x = height(root->lchild);
    y = height(root->rchild);

    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int Tree::count(Node *p)
{
    int x, y;

    if (p != nullptr)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}
