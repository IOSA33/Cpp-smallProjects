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
    // With reference: static void setID(Simple& const this, int id) {this.m_id = id}

    void print() const { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select member m_id

    // Returning *this for doing chainable function
    Simple& add(int value) {m_id += value; return *this;}
    Simple& sub(int value) {m_id -= value; return *this;}

    void reset() {
    *this = Simple(0);
        // value initialize a new object and overwrite the implicit object
    }
};

struct Something {
    int data{}; // member without m_, cause struct

    void setData(int data) {
    // because the function parameter shadows the data member
        this->data = data; // using this for disambiguate data parameter from member
    }
};

int main() {
    Simple simple{ 1 };
    simple.setID(2);
    // Compiler rewrites it as: Simple::setID(&simple, 2)

    // Chaining method
    simple.add(3).sub(4);

    simple.reset();

    simple.print();

    return 0;
}