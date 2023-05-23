#include <iostream>
#include "queue.h"
#include "node.h"
#include "tree.h"

int main(void)
{
    Tree t;
    t.create_tree();
    std::cout << "Preorder: ";
    t.preorder(t.root);
    std::cout << "\nInorder: ";
    t.inorder(t.root);
    int height = t.height(t.root);
    std::cout << "\nHeight: " << height << std::endl;
    int count = t.count(t.root);
    std::cout << "Node count: " << count << std::endl;

    return 0;
}