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

    return 0;
}