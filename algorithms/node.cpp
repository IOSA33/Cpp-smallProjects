#include <iostream>
#include <memory>

struct Node{
    int value{};
    std::unique_ptr<Node> next{nullptr};
    Node* prev{nullptr};
    Node* first{nullptr};
    Node* last{nullptr};

    explicit Node(const int x) : value(x) {
    }
};

void printList(const std::unique_ptr<Node>& head) {
    const Node* current = head.get();
    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next.get();
    }
}

std::unique_ptr<Node> deleteFirst(const std::unique_ptr<Node> &head) {
    if (head == nullptr) {
        return nullptr;
    }

    auto newHead = std::move(head->next);

    return newHead;
}

int main() {
    auto head = std::make_unique<Node>(8);
    head->next = std::make_unique<Node>(2);
    head->next->prev = head.get();
    head->next->next = std::make_unique<Node>(3);
    head->next->next->prev = head->next.get();

    head = deleteFirst(head);
    printList(head);

    return 0;
}