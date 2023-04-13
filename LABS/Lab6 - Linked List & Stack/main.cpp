#include <iostream>
using namespace std;

template <class T>
class LinkedNode
{
private:
    T data;
    LinkedNode *next;

public:
    LinkedNode() : next{nullptr} {}
    ~LinkedNode() { delete this->next; }

    void assign_next(LinkedNode<T> *node);
    void set_data(T data);
    LinkedNode<T> *get_next();
    T get_data();
};

template <class T>
LinkedNode<T> *LinkedNode<T>::get_next()
{
    return this->next;
}

template <class T>
void LinkedNode<T>::assign_next(LinkedNode<T> *node)
{
    this->next = node;
}

template <class T>
void LinkedNode<T>::set_data(T data)
{
    this->data = data;
}

template <class T>
T LinkedNode<T>::get_data()
{
    return this->data;
}

template <class T>
class LinkedList
{
private:
    LinkedNode<T> *first = nullptr;
    LinkedNode<T> *last = nullptr;
    int cnt = 0; // easily get the current number of items in the list
public:
    LinkedList() : first{nullptr}, last{nullptr}, cnt{0} {}
    bool isEmpty() { return first == 0; }
    int get_cnt() { return this->cnt; }
    void create_list();
    void display_list();
    void find_node_count();
    void append(T &elt);
    void insert(T &elt, int index); // i=0 first

    void deleteFirst(T &elt);
    void deleteLast(T &elt);
    void deleteNth(T &elt, int n);
};

template <class T>
void LinkedList<T>::display_list() // is displaying the list
{
    if (this->first == nullptr)
    {
        return;
    }

    if (this->cnt == 0)
    {
        this->find_node_count();
    }

    LinkedNode<T> *p = first;

    for (int i = 0; i < this->cnt; i++)
    {
        cout << p->get_data() << " ";
        p = p->get_next();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::find_node_count() // finding the number of nodes and assigning them into a class member called cnt
{
    LinkedNode<T> *p;
    int count = 0;
    p = first;

    while (p != nullptr)
    {
        count++;
        p = p->get_next();
    }

    this->cnt = count;
}

template <class T>
void LinkedList<T>::create_list() // to create the linked list
{
    int n, x;
    cout << "Please enter number of Nodes: ";
    cin >> n;

    cout << "Enter Node - 1: ";
    cin >> x;

    this->first = new LinkedNode<T>;
    this->first->set_data(x);
    this->first->assign_next(nullptr);
    this->last = this->first;

    LinkedNode<T> *temp;

    for (int i = 1; i < n; i++)
    {
        cout << "Enter Node - " << i + 1 << ": ";
        cin >> x;
        temp = new LinkedNode<T>;
        temp->set_data(x);
        temp->assign_next(nullptr);
        this->last->assign_next(temp);
        last = temp;
    }
}

template <class T>
void LinkedList<T>::append(T &elt) // adds a new element at the end as a node
{
    LinkedNode<T> *temp;

    temp = new LinkedNode<T>;

    temp->assign_next(nullptr);
    temp->set_data(elt);

    this->last->assign_next(temp);
    this->last = temp;

    this->cnt++;
}

template <class T>
void LinkedList<T>::insert(T &elt, int index) // inserting a new element into a specific space
{
    if (index < 1 || index > this->cnt)
    {
        return;
    }

    LinkedNode<T> *temp;
    temp = new LinkedNode<T>;
    temp->data = elt;

    LinkedNode<T> *p = first;

    if (index == 0) // insert to the first index
    {
        temp->next = first->next;
        first = temp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

template <class T>
void LinkedList<T>::deleteFirst(T &elt)
{
}

template <class T>
void LinkedList<T>::deleteLast(T &elt)
{
}

template <class T>
void LinkedList<T>::deleteNth(T &elt, int i)
{
}

template <class T>
class Stack
{
private:
    T *data;
    int Top;
    int Capacity;

public:
    Stack(int sz = 10)
    {
        data = new T[sz];
        Capacity = sz;
        Top = -1;
    }
    bool isEmpty() { return Top == -1; }
    int cntElts() { return Top + 1; }
};

template <class T>
class StackLL
{
private:
    LinkedList<T> data;
    int Top;
    int Capacity;

public:
    StackLL() { data = new LinkedList<T>; }
    bool isEmpty() { return data.isEmpty(); }
    int cntElts() { return this->data.cnt; }
    void pop(T &x);
    void push(T &x);
};

template <class T>
void StackLL<T>::pop(T &x)
{
}

template <class T>
void StackLL<T>::push(T &x)
{
}

int main(int argc, char *argv[])
{
    // Stack<int> S1;
    // Stack<string> S2(3);

    LinkedList<int> l1;

    l1.create_list();
    l1.display_list();

    int x = 6;

    l1.append(x);
    l1.display_list();

    return 0;
}