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

// We just recompile for specific template the class function
// if this definition is in header file this should mark as 'inline'.
// Because explicit function specializations are not implicitly inline.
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