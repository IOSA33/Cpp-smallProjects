template<typename T>;
class Node {
public:
    T data; // Data represents the value stored in the node of the tree
    Node* left; // left is the pointer to the left child of the node
    Node* right; // right same as left

    // Constructor to initialize the node with a value
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

int main() {
    return 0;
}