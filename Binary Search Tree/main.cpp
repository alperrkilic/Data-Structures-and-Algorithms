#include <iostream>
#include "node.h"
#include "binary_tree.h"

int main(void)
{
    BinaryTree tree;
    std::vector<int> numbers = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    tree.generate_bst(numbers);
    std::cout << "Preorder  : ";
    tree.preorder_traversal(tree.root);
    std::cout << std::endl;
    std::cout << "Inorder   : ";
    tree.inorder_traversal(tree.root);
    std::cout << std::endl;
    std::cout << "Postorder : ";
    tree.postorder_traversal(tree.root);

    return 0;
}