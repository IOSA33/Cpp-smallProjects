#include <iostream>
#include <print>
#include <cassert>

template <typename T>
class VectorInt {
private:
    int m_length{};
    T* m_data{};

public:
    VectorInt(int length) {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    } 

    VectorInt(const VectorInt&) = delete;
    VectorInt& operator=(const VectorInt&) = delete;

    ~VectorInt() {
        delete[] m_data;
    }

    T& operator[] (int index) {
        return m_data[index];
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const { return m_length; }
};


int main() {

    VectorInt<int> vec { 5 };
    vec[3] = 3;
    std::println("Value in index of 3 is {}", vec[3]);

    return EXIT_SUCCESS;
}