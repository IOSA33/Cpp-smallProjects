#include <iostream>
#include <queue>
using namespace std;


template <typename T>
class Node {
public:
    T data; // Data represents the value stored in the node of the tree
    Node* left; // left is the pointer to the left child of the node
    Node* right; // right same as left

    // Constructor to initialize the node with a value
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    // Pointer to the root of the tree
    Node<T>* root;

    // Helper Function to find the minimum value node
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Recursive Function to search for a value in the tree
    bool searchRecursive(Node<T>* current, T value) {
        if (current == nullptr) return false;
        if (current->data == value) return true;
        return searchRecursive(current->left, value) || searchRecursive(current->right, value);
    }


    int calculateMaxPaht(Node<T>* currentNode) {
        if (currentNode == nullptr) return 0;

        int maxLeft = calculateMaxPaht(currentNode->left);
        int maxRight = calculateMaxPaht(currentNode->right);

        return currentNode->data + std::max(maxLeft, maxRight);
    }

public:
    // Constructor to initialize the tree
    BinaryTree() : root(nullptr) {}

    // Function to insert a nod ein the binary tree
    void insertNode(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();

            if (current->left ==nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right ==nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    bool search(T value) {
        return searchRecursive(root, value);
    }
};

int main() {
    BinaryTree<int> tree;

    tree.insertNode(1);
    tree.insertNode(4);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(5);
    tree.insertNode(4);
    tree.insertNode(2);

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;



    return 0;
}