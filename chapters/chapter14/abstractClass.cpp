#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
    std::cout << "=== Example 1: Default Objects ===" << std::endl;
    Dog dog("Dog");
    Cat cat("Cat");

    dog.sleep();
    dog.makeSound();
    cat.sleep();
    cat.makeSound();

    std::cout << "\n=== Example 2: Polymorphism ===" << std::endl;
    Animal* animal1 = new Dog("Rex");
    Animal* animal2 = new Cat("Leo");

    animal1->makeSound();  // Rex Saying woof!
    animal1->sleep();      // Rex sleeps

    animal2->makeSound();  // Leo Saying may!
    animal2->sleep();      // Leo sleeps

    // Realising memory
    delete animal1;
    delete animal2;

    std::cout << "\n=== Example 3: unique pointers ===" << std::endl;
    std::unique_ptr<Animal> animal3 = std::make_unique<Dog>("Buddy");
    std::unique_ptr<Animal> animal4 = std::make_unique<Cat>("Luna");

    animal3->makeSound();  // Buddy Saying woof!
    animal4->makeSound();  // Luna Saying may!

    std::cout << "\n=== Example 4: Vector animals ===" << std::endl;
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Dog>("Charlie"));
    zoo.push_back(std::make_unique<Cat>("Molly"));
    zoo.push_back(std::make_unique<Dog>("Max"));

    for (const auto& animal : zoo) {
        animal->makeSound(); // Every animal making sound
    }

    return 0;
}