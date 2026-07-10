#include <iostream>

template<typename T>
class Auto_ptr3 {
private:
    T* m_ptr{};
public:
    Auto_ptr3(T* ptr = nullptr) 
    : m_ptr(ptr) {}

    ~Auto_ptr3() {
        delete m_ptr;
    }

    // Copy contructor
    // Deep copy
    Auto_ptr3(const Auto_ptr3& a) {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    // Copy Assigment
    Auto_ptr3& operator=(const Auto_ptr3& a) {
        if (&a == this) {
            return *this;
        }

        delete m_ptr;

        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

    T& operator*() const { return *this; }
    T* operator->() const { return this; }
    bool isNull() { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateAutoClass() {
    Auto_ptr3<Resource> res { new Resource };
    return res;
}

int main() {
    Auto_ptr3<Resource> main_res;
    main_res = generateAutoClass();
}