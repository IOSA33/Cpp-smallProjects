template<typename T>;
class Node {
public:
    T data; // Data represents the value stored in the node of the tree
    Node* left; // left is the pointer to the left child of the node
    Node* right; // right same as left

    // Constructor to initialize the node with a value
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
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
    bool serchRecursive(Node<T>* current, T value) {
        if (current == nullptr) return false;
        if (current->data == value) return true;
        return serchRecursive(current->left, value) || serchRecursive(current->right, value);
    }

};

int main() {
    return 0;
}