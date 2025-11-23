#include <iostream>
#include <queue>

class Node {
public:
    int m_data {};
    Node* m_left { nullptr };
    Node* m_right { nullptr };

    explicit Node(int data) : m_data(data)
    {}
};

class BinaryTree {
private:
    Node* m_root { nullptr };

    bool search(Node* current, int data) {
        if (current == nullptr) return false;
        if (current->m_data == data) return true;
        return search(current->m_left, data) || search(current->m_right, data); 
    }

public:
    BinaryTree() = default;

    void insertNode(int value) {
        Node* newNode = new Node{ value };

        if (m_root == nullptr) {
            m_root = newNode;
            return;
        }

        std::queue<Node*> q;
        q.push(m_root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->m_left == nullptr) {
                current->m_left = newNode;
                return;
            } else {
                q.push(current->m_right);
            }
        }
    }


    void printLeftTree() {
        while (m_root->m_left != nullptr) {

        }
    }
};


int main() {

    return 0;
}