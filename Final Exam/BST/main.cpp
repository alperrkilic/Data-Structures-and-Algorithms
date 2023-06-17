#include <iostream>

class BinaryTree
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int data) : data(data), left(nullptr), right(nullptr) {}
    } *root;
    int size;

    BinaryTree(int data)
    {
        this->root = new Node(data);
        this->size++;
    }
    ~BinaryTree() {}

    void insert(Node *&node, int data)
    {
        if (node == nullptr)
        {
            node = new Node(data);
            return;
        }
        if (node->data == data)
        {
            return;
        }
        if (node->data < data)
        {
            return this->insert(node->right, data);
        }
        return this->insert(node->left, data);
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->data << " ";
        this->preorder(node->left);
        this->preorder(node->right);
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        this->inorder(node->left);
        std::cout << node->data << " ";
        this->inorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        this->postorder(node->left);
        this->postorder(node->right);
        std::cout << node->data << " ";
    }

    int height(Node *node)
    {
        int left, right;
        if (node == nullptr)
        {
            return 0;
        }
        left = this->height(node->left);
        right = this->height(node->right);
        if (left > right)
        {
            return left + 1;
        }
        return right + 1;
    }

    int count(Node *node)
    {
        int left, right;
        if (node == nullptr)
        {
            return 0;
        }

        left = this->count(node->left);
        right = this->count(node->right);

        return left + right + 1;
    }

    Node *search(Node *node, int data)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data == data)
        {
            return node;
        }
        if (node->data < data)
        {
            return this->search(node->right, data);
        }
        return this->search(node->left, data);
    }

    // AĞLAMAYIN
    void insert(int data)
    {
        this->insert(this->root, data);
        this->size++;
    }
};

int main()
{

    BinaryTree tree{50};

    tree.insert(7);
    tree.insert(2);
    tree.insert(78);
    tree.insert(12);
    tree.insert(8);
    tree.insert(0);

    std::cout << "PREORDER: " << std::endl;
    tree.preorder(tree.root);
    std::cout << std::endl;

    std::cout << "INORDER: " << std::endl;
    tree.inorder(tree.root);
    std::cout << std::endl;

    std::cout << "POSTORDER: " << std::endl;
    tree.postorder(tree.root);
    std::cout << std::endl;

    std::cout << tree.height(tree.root) << std::endl;

    std::cout << tree.count(tree.root) << std::endl;

    BinaryTree::Node *result = tree.search(tree.root, 8);

    if (result == nullptr)
    {
        std::cout << "YOK" << std::endl;
    }
    else
    {
        std::cout << result->data << std::endl;
    }

    return 0;
}