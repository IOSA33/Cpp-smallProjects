#include <iostream>

class Ball {
    std::string m_color{ "black" };
    double m_radius{10.0};

public:
    Ball() = default;
    Ball(double radius) : m_radius(radius) {
        print();
    }
    Ball(std::string_view color) : m_color(color) {
        print();
    }
    Ball(std::string_view color, double radius) : m_color(color), m_radius(radius) {
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