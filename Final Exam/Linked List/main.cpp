#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList(/* args */) { this->first = nullptr; }
    ~LinkedList() { delete this->first; }

    void display()
    {
        Node *p = this->first;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void insert(int data, int pos)
    {
        Node *t = new Node;
        t->data = data;
        Node *p = this->first;

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

    Node *find_last()
    {
        Node *p = this->first;

        while (p != nullptr)
        {
            p = p->next;
        }

        return p;
    }

    void push_back(int data)
    {
        Node *t = new Node;
        t->data = data;
        t->next = nullptr;

        if (this->first == nullptr)
        {
            this->first = t;
        }
        else
        {
            Node *last = this->find_last();
            last->next = t;
        }
    }

    int find_length()
    {
        Node *p = this->first;
        int length{0};

        while (p != nullptr)
        {
            length++;
            p = p->next;
        }

        return length;
    }

    int delete_node(int index)
    {
        Node *p, *q = nullptr;
        int x = -1;

        if (index < 1 || index > this->find_length())
        {
            cout << "Invalid Index" << endl;
            return x;
        }

        if (index == 1)
        {
            p = this->first; // p holds the address of first
            this->first = this->first->next;
            x = p->data;
            delete p;
            return x;
        }
        else
        {
            p = this->first;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
        }
        return x;
    }
};

int main(void)
{
    return 0;
}