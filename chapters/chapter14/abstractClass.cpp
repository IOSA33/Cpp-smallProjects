#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    virtual ~Animal() = default;

    void sleep() {
        std::cout << name << " sleeps" << std::endl;
    }

    virtual void makeSound() = 0; // pure virtual function
};

class Dog : public Animal {
public:
    Dog(const std::string& name) {
        this->name = name;
    }

    void makeSound() override {
        std::cout << name << " Saying woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& name) {
        this->name = name;
    }

    void makeSound() override {
        std::cout << name << " Saying may!" << std::endl;
    }
};

int main() {

}