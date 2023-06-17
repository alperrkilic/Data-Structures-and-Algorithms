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
    ~LinkedNode() {}

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
    void deleteNth(T &elt, int index);
    LinkedNode<T> *get_first();
    T get_last_data();
};

template <class T>
T LinkedList<T>::get_last_data()
{
    return this->last->get_data();
}

template <class T>
LinkedNode<T> *LinkedList<T>::get_first()
{
    return this->first;
}

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

    LinkedNode<T> *p = this->first;

    while (p != nullptr)
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
    this->cnt = n;

    LinkedNode<T> *temp;

    for (int i = 1; i < n; i++)
    {
        cout << "Enter Node - " << i + 1 << ": ";
        cin >> x;
        temp = new LinkedNode<T>;
        temp->set_data(x);
        temp->assign_next(nullptr);
        this->last->assign_next(temp);
        this->last = temp;
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
    LinkedNode<T> *p = this->first;

    first = first->get_next();

    elt = p->get_data();
    delete p;
    this->cnt--;
}

template <class T>
void LinkedList<T>::deleteLast(T &elt)
{
    LinkedNode<T> *p = first;

    while (p->get_next() != last) // p will point on the last element
    {
        p = p->get_next();
    }

    elt = this->last->get_data();

    delete this->last;
    p->assign_next(nullptr);
    this->last = p;
    this->cnt--;
}

template <class T>
void LinkedList<T>::deleteNth(T &elt, int index)
{
    LinkedNode<T> *p = this->first;
    LinkedNode<T> *q = nullptr;

    /*
        8    3     9     7     6
        1    2     3     4     5
        p    p     p     p
        q    q     q

        Delete 4: (index = 4) --> element to be deleted is 7
        p starts from first which is index 1
        will be shifted 3 times from starting 0 to 4-1 shift
        q will be the previous of p will and q->next will point to the p->next
    */

    for (int i = 0; i < index - 1; i++)
    {
        q = p;
        p = p->get_next();
    }

    q->assign_next(p->get_next()); // q->next = p->next;
    elt = p->get_data();
    delete p;
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
    LinkedList<T> *data;
    T Top;
    int Capacity{0};

public:
    StackLL() { data = new LinkedList<T>; }
    bool isEmpty() { return data.isEmpty(); }
    int cntElts() { return this->data.cnt; }
    void create_linked_list();
    void display_linked_list();
    void pop(T &x);
    void push(T &x);
    T get_top();
};

template <class T>
T StackLL<T>::get_top()
{
    return this->Top;
}

template <class T>
void StackLL<T>::display_linked_list()
{
    this->data->display_list();
}

template <class T>
void StackLL<T>::create_linked_list()
{
    this->data->create_list();
}

template <class T>
void StackLL<T>::pop(T &x)
{

    if (this->data->get_first() != nullptr)
    {
        this->data->deleteLast(x);
        Capacity--;
        if (this->data->get_first() != nullptr) // check if there's still a node to store the new top
        {
            this->Top = data->get_last_data(); // top will be the last element's data
        }
    }
    else // if first element does not exist, then do nothing
    {
        return;
    }
}

template <class T>
void StackLL<T>::push(T &x)
{
    this->Top = x;         // the element that is pushed will be on top
    this->data->append(x); // and will be appended to the linked list
    this->Capacity++;
}

int main(int argc, char *argv[])
{

    // Linked List Application
    // LinkedList<int> l1;

    // l1.create_list();
    // l1.display_list();

    // int append_value{6};
    // int delete_last{0};
    // int delete_first{0};

    // cout << "Append: " << append_value << endl;
    // l1.append(append_value);
    // l1.display_list();

    // l1.deleteLast(delete_last);
    // cout << "Delete Last (" << delete_last << "):" << endl;
    // l1.display_list();

    // l1.deleteFirst(delete_first);
    // cout << "Delete First (" << delete_first << "):" << endl;
    // l1.display_list();

    // Stack Application

    int k = 10;
    int old_top = 0;

    StackLL<int> stackL1;
    stackL1.create_linked_list();
    cout << "\nDisplaying The Linked List that has been created: ";
    stackL1.display_linked_list();

    cout << "\nPushing " << k << " at the end of the list. New list is: ";
    stackL1.push(k);
    stackL1.display_linked_list();

    auto p = stackL1.get_top();
    cout << "\nAfter pushing " << k << ", new Top value is: " << p << endl;

    stackL1.pop(old_top);
    auto q = stackL1.get_top();
    cout << "\nPopping the last element: " << q << endl;
    cout << "Old Top Value is: " << old_top << endl;
    cout << "New Top Value after popping the last is: " << q << endl;
    stackL1.display_linked_list();

    return 0;
}