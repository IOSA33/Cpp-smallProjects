#include <iostream>

class Fruit {
public:
    enum Type {
        apple,
        banana,
        cherry
    };

private:
    Type m_type {};
    int m_percentage {0};

public:
    explicit Fruit(Type fruit) : m_type { fruit } {
    }

    Type getType() const {return m_type;}
    int getPercentage() const {return m_percentage;}

    bool isCherry() const {return m_type == cherry;}
};


int main()
{
    // Note: Outside the class, we access the enumerators via the Fruit:: prefix now
    Fruit apple { Fruit::apple };

    if (apple.getType() == Fruit::apple)
        std::cout << "I am an apple";
    else
        std::cout << "I am not an apple";

    return 0;
}