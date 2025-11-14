#include <iostream>

class Simple {
private:
    int m_id{};

public:
    Simple(int id)
        : m_id{ id } {
    }

    int getID() const { return m_id; }
    void setID(int id) { m_id = id; }
    // Compiler rewrites it as:
    // static void setID(Simple* const this, int id) { this->m_id = id; }

    void print() const { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select member m_id
};

struct Something {
    int data{}; // member without m_, cause struct

    void setData(int data) {
        this->data = data; // using this for disambiguate data parameter from member
    }
};

int main() {
    Simple simple{ 1 };
    simple.setID(2);
    // Compiler rewrites it as: Simple::setID(&simple, 2)

    simple.print();

    return 0;
}