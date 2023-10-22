#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
   public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { destroyTree(root); }

    void insert(const T& value) { insert(root, value); }

    bool search(const T& value) { return search(root, value); }

    void remove(const T& value) { remove(root, value); }

    void printPreOrder() {
        printPreOrder(root);
        std::cout << std::endl;
    }

   private:
    Node<T>* root;

    void destroyTree(Node<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void insert(Node<T>*& node, const T& value) {
        if (!node) {
            node = new Node<T>(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        }
    }

    bool search(Node<T>* node, const T& value) {
        if (!node) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    void remove(Node<T>*& node, const T& value) {
        if (!node) {
            return;
        } else if (value < node->data) {
            remove(node->left, value);
        } else if (value > node->data) {
            remove(node->right, value);
        } else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
            } else if (!node->left) {
                Node<T>* temp = node;
                node = node->right;
                delete temp;
            } else if (!node->right) {
                Node<T>* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node<T>* minNode = node->right;
                while (minNode->left) {
                    minNode = minNode->left;
                }
                node->data = minNode->data;
                remove(node->right, minNode->data);
            }
        }
    }

    void printPreOrder(Node<T>* node) {
        if (node) {
            std::cout << node->data << " ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }
};

int main() {
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    std::cout << "Binary Tree in Preorder: ";
    tree.printPreOrder();

    int valueToFind = 3;
    if (tree.search(valueToFind)) {
        std::cout << valueToFind << " found in the tree." << std::endl;
    } else {
        std::cout << valueToFind << " not found in the tree." << std::endl;
    }

    int valueToRemove = 5;
    tree.remove(valueToRemove);

    std::cout << "Binary Tree after removing " << valueToRemove << ": ";
    tree.printPreOrder();

    return 0;
}
