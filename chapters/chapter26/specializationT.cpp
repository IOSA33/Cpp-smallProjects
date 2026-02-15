#include <iostream>

template <typename T>
class Storage {
private:
    T m_value{};
public:
    Storage(T value) : m_value(value) {} 
    void print() {
        std::cout << m_value << '\n';
    }
};

template<>
void Storage<double>::print() {
    std::cout << std::scientific << m_value << '\n';
}

int main() {
    Storage i { 5 };
    Storage d { 5.5 };

    i.print();
    d.print();
}