#include <iostream>
class BinaryTree
{
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    } *root;
    Node* recurSiveInsert(Node* root, int value, Node* parent = nullptr) // Добавляем параметр parent
    {
        if (root == nullptr)
        {
            Node* newNode = new Node(value);
            return newNode;
        }
        if (value < root->data)
        {
            root->left = recurSiveInsert(root->left, value, root); // Передаем текущий узел как родителя
        }
        else if (value > root->data)
        {
            root->right = recurSiveInsert(root->right, value, root); // Передаем текущий узел как родителя
        }

        return root;
    }
public:
    int countOfSubtrees(int min_height, int max_height){
        return slaveCountOfSubtrees(root, min_height, max_height, 0);
    }
    int slaveCountOfSubtrees(Node* node, int min_height, int max_height, int depth) {
        int countSubTrees = 0;

        if (node == nullptr) {
            return 0;
        }

        if (depth >= min_height && depth < max_height) {
            if (isLeaf(node->left)) {
                countSubTrees += depth;
            }
            if (isLeaf(node->right)) {
                countSubTrees += depth;
            }
        }

        countSubTrees += slaveCountOfSubtrees(node->left, min_height, max_height, depth + 1);
        countSubTrees += slaveCountOfSubtrees(node->right, min_height, max_height, depth + 1);

        return countSubTrees;
    }

    bool isLeaf(Node* node){
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
    void print(Node* node){

    std::cout<<node->data<<' ';
    }
    void insert(int value)
    {
        root = recurSiveInsert(root, value);
    }
};
int main(){
    BinaryTree tree;
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
  //  tree.insert(0);
    std::cout<<std::endl;
    std::cout<<tree.countOfSubtrees(2,3);

}