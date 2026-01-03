#include <array>
#include <iostream>
#include <print>

constexpr int g_MAX_SIZE = 10;

class QueueO2 {
    int m_capacity{};
    int m_size{};
    std::array<int, g_MAX_SIZE> m_queue {};
public:
    explicit QueueO2(const int capacity)
    : m_capacity(capacity) {}

    void enqueue(const int x) {
        if (m_size == m_capacity) {
            std::cout << "Queue is full\n";
        }
        m_queue[m_size++] = x;
        std::cout << "Added to the queue: " << x << std::endl;
    }
    int dequeue() {
        if (m_size != 0) {
            const int temp{m_queue[0]};
            for (int i{0}; i < m_size; ++i) {
                m_queue[i] = m_queue[i+1];
            }
            --m_size;
            return temp;
        }
        return -1;
    }
    bool isEmpty() const {
        return m_size == 0;
    }
    int size() const {
        return m_size;
    }
    int front() const {
        if (!isEmpty()) {
            return m_queue[0];
        }
        return -1;
    }
};


int main() {
    QueueO2 q{g_MAX_SIZE};
    std::printf("Empty: %o!\n", q.isEmpty());
    std::cout << "The queue is empty? Empty: " << q.isEmpty() << std::endl;
    std::cout << "Size of the queue: " << q.size() << std::endl;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    std::cout << "The queue is empty? Empty: " << q.isEmpty() << std::endl;
    std::cout << "Size of the queue: " << q.size() << std::endl;
    std::cout << "Current Front digit is: " << q.front() << std::endl;
    std::cout << "Returned value of the dequeue is: " << q.dequeue() << std::endl;
    std::cout << "Current Front digit is: " << q.front() << std::endl;

    return EXIT_SUCCESS;
}