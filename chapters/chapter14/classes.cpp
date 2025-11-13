#include <iostream>

// If your class type has no data members, prefer using a namespace.
class Employee {
public:
    int m_id{};
    int m_age{};
    double m_wage{};
    int noInitVal;

    // Employee() = default; // Explicitly defaulted default constructor
    void printInfo() {
        std::cout << "Id: " << m_id << std::endl;
    }
};

class TopEmployee {
    std::string m_name{};
    int m_id{};
    bool m_isManager{ false };

    void printCreated() {
        std::cout << "Employee  " << m_name << std::endl;
    }
public:
    TopEmployee(std::string name, int id) : m_name(name), m_id(id) {
        printCreated();
    }

    TopEmployee(std::string name, int id, bool isManager) : m_name(name), m_id(id), m_isManager(isManager) {
        printCreated();
    }
};

struct Person {
    std::string name;
    int age;

    void Kisses(const Person& person) {
        std::cout << name << " kisses " << person.name << std::endl;
    }

    // const function
    void print() const {
        std::cout << name << std::endl;
    }
};

int main() {
    Employee e{.m_id = 1, .m_age = 23, .m_wage = 67000};
    e.printInfo();

    Person iosa{.name = "Iosa", .age = 20};
    Person alisa{"Alisa", 19};

    // Now we can use const functions
    const Person tester{"tester", 18};
    tester.print();

    TopEmployee e1{"James", 7};
    TopEmployee e2{"James", 7, true};

    iosa.Kisses(alisa);

    return EXIT_SUCCESS;
}