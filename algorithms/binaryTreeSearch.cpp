#include <iostream>
#include <queue>

class Node {
public:
    int m_data {};
    Node* m_left { nullptr };
    Node* m_right { nullptr };

    explicit Node(const int data) : m_data(data)
    {}
};

class BinaryTree {
private:
    Node* m_root { nullptr };

    bool m_search(const Node* current, const int data) {
        if (current == nullptr) return false;
        if (current->m_data == data) return true;
        return m_search(current->m_left, data) || m_search(current->m_right, data); 
    }

    int m_MaxHeight(const Node* current) {
        if (current == nullptr) return 0;
        int rightPath = m_MaxHeight(current->m_right);
        int leftPath = m_MaxHeight(current->m_left);

        return 1 + (leftPath > rightPath ? rightPath : leftPath);
    }

    int findLevel(const Node *current, const int k, const int level) {
        if (current == nullptr) return -1;
        if (current->m_data == k) return level;

        int leftLevel = findLevel(current->m_left, k, level + 1);

        if (leftLevel == -1) return findLevel(current->m_right, k, level + 1);
        return leftLevel;
    }
    
    Node* LCA(Node* current, int node1, int node2) {
        if (current == nullptr) return current;
        if (current->m_data == node1 || current->m_data == node2) return current;

        Node* left = LCA(current->m_left, node1, node2);
        Node* right = LCA(current->m_right, node1, node2);

        if (left != nullptr && right != nullptr) return current;
        if (left == nullptr && right == nullptr) return nullptr;

        return (left != nullptr) ? LCA(current->m_left, node1, node2) : LCA(current->m_right, node1, node1); 
    }

    int m_distance(Node* current, int a, int b) {
        Node* lca = LCA(current, a, b);

        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);

        return d1 + d2;
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
                q.push(current->m_left);
            }
            if (current->m_right == nullptr) {
                current->m_right = newNode;
                return;
            } else {
                q.push(current->m_right);
            }
        }
    }

    void search(int data) {
        m_search(m_root, data);
    }

    int height() {
        return m_MaxHeight(m_root);
    }

    int distance(int x, int y) {
        return m_distance(m_root, x, y);
    }
};


int main() {

    BinaryTree tree{};
    tree.insertNode(30);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(10);

    std::cout << tree.height() << std::endl;
    std::cout << tree.distance(10, 40) << std::endl; // Needs to print 3

    return 0;
}