#include <iostream>

class Base {
private:
    int m_value {};

public:
    Base(int value) : m_value(value) {}
    int getValue() const { return m_value; }
};

class Derived :  public Base {
public:
    Derived(int value) : Base { value } {}

    int getValue() const = delete;
};

int main() {
    Derived d { 7 };
    std::cout << d.Base::getValue();

    return 0;
}
