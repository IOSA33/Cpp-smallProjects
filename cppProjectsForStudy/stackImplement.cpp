#include <iostream>

class MyStack {
    int *arr;
    int capasity;
    int top;

public:
    explicit MyStack(const int cap) {
        capasity = cap;
        arr = new int[capasity];
        top = -1;
    }

    void getElemtns() {
        if (!isEmpty()) {
            for (int i = 0; i < 4; ++i) {
                std::cout << i << " element position, value is: " << arr[i] << std::endl;
            }
        }
    }

    void push(const int n) {
        if (top == capasity-1) {
            std::cout << "Stack is Overflow \n";
            return;
        }
        arr[++top] = n;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack is Underflow\n";
            return -1;
        }
        return arr[--top];
    }

    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty, we cannot check top element of it!\n";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        if (top == -1) {
            std::cout << "Stack is empty\n";
            return true;
        }

        return false;
    }

    bool isFull() {
        return top == capasity - 1;
    }
};

int main() {
    MyStack stack(4);

    std::cout << stack.isEmpty() << std::endl;

    stack.pop();

    stack.push(2);
    stack.push(23);
    stack.push(9);

    std::cout << "Stack is full? " << stack.isFull() << std::endl;

    stack.push(3);

    std::cout << "Stack is full? " << stack.isFull() << std::endl;

    std::cout << stack.peek() << std::endl;

    std::cout << stack.pop() << std::endl;

    stack.getElemtns();
}
