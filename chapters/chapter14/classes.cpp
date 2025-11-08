#include <iostream>

// If your class type has no data members, prefer using a namespace.
class Employee {
public:
    int m_id{};
    int m_age{};
    double m_wage{};

    void printInfo() {
        std::cout << "Id: " << m_id << std::endl;
    }
};

struct Person {
    std::string name;
    int age;

    void Kisses(const Person& person) {
        std::cout << name << " kisses " << person.name << std::endl;
    }
};

int main() {
    Employee e{.m_id = 1, .m_age = 23, .m_wage = 67000};
    e.printInfo();

    Person iosa{.name = "Iosa", .age = 20};
    Person alisa{"Alisa", 19};

    iosa.Kisses(alisa);

    return EXIT_SUCCESS;
}