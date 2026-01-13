#include <iostream>

class A {
public:
    int m_value{};
};

class B : public A {
private:
    using A::m_value;

public:
    B(int value) : A{value}
    {}

};

int main() {
    B b{7};
    A& a{b};
    a.m_value;
}   