#include <iostream>
#include <vector>

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
    struct Subtree {
        Node<T>* root;
        Subtree(Node<T>* node) : root(node) {}
        };

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        destroyTree(root);
        }

    void insert(const T& value) {
        insert(root, value);
        }

    bool search(const T& value) {
        return search(root, value);
        }

    void remove(const T& value) {
        remove(root, value);
        }

    void printPreOrder() {
        printPreOrder(root);
        std::cout << std::endl;
        }

    // Метод для поиска поддеревьев, листья которых находятся в заданном диапазоне высот
    std::vector<Subtree> findSubtreesWithLeafHeightInRange(int min_height, int max_height) {
        std::vector<Subtree> result;
        findSubtreesWithLeafHeightInRange(root, 0, min_height, max_height, result);
        return result;
        }

    void printSubtreePreOrder(Node<T>* node) {
        if (node) {
            // Print the current node's value
            /*for (int i = 0; i < depth; ++i) {
                std::cout << "  "; // Indent for hierarchy
            }*/
            std::cout << node->data << ' ';

            // Print left and right subtrees with increased depth
            printSubtreePreOrder(node->left);
            printSubtreePreOrder(node->right);
            }
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
            }
        else if (value < node->data) {
            insert(node->left, value);
            }
        else if (value > node->data) {
            insert(node->right, value);
            }
        }

    bool search(Node<T>* node, const T& value) {
        if (!node) {
            return false;
            }
        else if (value == node->data) {
            return true;
            }
        else if (value < node->data) {
            return search(node->left, value);
            }
        else {
            return search(node->right, value);
            }
        }

    void remove(Node<T>*& node, const T& value) {
        if (!node) {
            return;
            }
        else if (value < node->data) {
            remove(node->left, value);
            }
        else if (value > node->data) {
            remove(node->right, value);
            }
        else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
                }
            else if (!node->left) {
                Node<T>* temp = node;
                node = node->right;
                delete temp;
                }
            else if (!node->right) {
                Node<T>* temp = node;
                node = node->left;
                delete temp;
                }
            else {
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

    void findSubtreesWithLeafHeightInRange(Node<T>* node, int current_height, int min_height, int max_height, std::vector<Subtree>& result) {
        if (node == nullptr) {
            return;
            }

        if (current_height >= min_height && current_height <= max_height) {
            Subtree subtree(node);
            result.push_back(subtree);
            }
        if (current_height < max_height) {

            findSubtreesWithLeafHeightInRange(node->left, current_height + 1, min_height, max_height, result);
            //std::cout<<node->data<<" ";
            findSubtreesWithLeafHeightInRange(node->right, current_height + 1, min_height, max_height, result);
            //std::cout<<node->data<<" ";
            }
        }
    };

int main() {
    BinaryTree<int> tree;

    tree.insert(6);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(10);
    tree.insert(9);
    tree.insert(7);
    tree.insert(5);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(15);

    std::cout << "Binary Tree in Preorder: ";
    tree.printPreOrder();
    std::cout << std::endl;

    int min_height = 1;
    int max_height = 2;
    std::vector<BinaryTree<int>::Subtree> subtrees = tree.findSubtreesWithLeafHeightInRange(min_height, max_height);

    std::cout << "Subtrees with leaf height in range [" << min_height << ", " << max_height << "]:\n";
    for (const BinaryTree<int>::Subtree& subtree : subtrees) {
        std::cout << "Subtree Preorder: ";
        tree.printSubtreePreOrder(subtree.root);
        std::cout << std::endl;
        }

    return 0;
    }
