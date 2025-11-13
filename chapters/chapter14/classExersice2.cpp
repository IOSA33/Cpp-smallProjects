#include <iostream>

class Ball {
    std::string m_color{ "black" };
    double m_radius{10.0};

public:
    explicit Ball(const double radius) : Ball("black", radius) {}
    explicit Ball(const std::string_view color="black", const double radius=10.0)
    : m_color(color), m_radius(radius) {
        print();
    }

    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main() {
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}