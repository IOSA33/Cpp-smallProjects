#include <iostream>
#include <string>
#include <string_view>

class Animal {
private:
    std::string m_name{};

public:
    virtual std::string_view getName() { return "ANIMAL"; }
};

class Dog : public Animal{
public:
    std::string_view getName() { return "DOG"; }
};

class Poodle : public Dog {
public:
    std::string_view getName() { return "POODLE"; }
};

int main() {
    Poodle dog{};
    Animal& rAnimal{ dog };
    std::cout << rAnimal.getName() << std::endl;
}