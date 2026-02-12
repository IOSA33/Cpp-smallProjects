#include <iostream>
#include <print>
#include <cassert>
#include <initializer_list>

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

    VectorInt(std::initializer_list<T> list) 
        : VectorInt(static_cast<int>(list.size())) 
    {
        std::copy(list.begin(), list.end(), m_data);
    }

    VectorInt(const VectorInt&) = delete;
    VectorInt& operator=(const VectorInt&) = delete;

    ~VectorInt() {
        delete[] m_data;
    }

    T& operator[] (int index);

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const { return m_length; }
};
// Best parctice
// is just put template func definition in the same file as header
template <typename T>
T& VectorInt<T>::operator[](int index){
    assert(index >= 0 && index < m_length);
    return m_data[index];
} 

// g++ -std=c++26 ownContainer.cpp -lstdc++exp -o own
int main() {

    VectorInt<int> vec { 5 };
    vec[0] = 3;
    std::println("Value in index of 3 is {}", vec[0]);

    VectorInt<double> vec1 { 5.2, 3.1, 2.4, 2.22 };
    for (int i{ 0 }; i < vec1.getLength(); ++i) {
        std::print("{} ", vec1[i]);
    }
{}
    return EXIT_SUCCESS;
}