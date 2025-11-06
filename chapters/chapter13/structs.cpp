#include <iostream>

struct Employee {
    int x;       // no default initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value, already with value

    int id{}; // data members
    int age{};

    double wage{};
};

std::ostream& operator<<(std::ostream& out, const Employee& e) {
    out << "id: " << e.id << " Age: " << e.age << " Wage: "<< e.wage;
    return out;
}

int main() {

    // Best practice:
    // For aggregates, prefer value initialization (with an empty braces initializer)
    // to default initialization (with no braces). emp is bad example, prefer do not do that.

    // Default initialization
    Employee emp; //   int x; will not initialize
    // The value initialization
    Employee joe {};// This is safer, because it prevents us from missing values: int x; will be 0
    joe.id = 14;
    joe.age = 32;
    joe.wage = 60000.0;

    Employee frank {};
    frank.id = 15;
    frank.age = 28;
    frank.wage = 45000.0;

    Employee joy {.id = 1, .age = 1, .wage = 2}; // c++20
    Employee joy2 {joy}; // direct-list-initialization

    int totalAge {joe.age + frank.age};
    std::cout << totalAge << std::endl;
    std::cout << joe << std::endl;

    if (joe.wage > frank.wage)
        std::cout << "Joe makes more than Frank\n";
    else if (joe.wage < frank.wage)
        std::cout << "Joe makes less than Frank\n";
    else
        std::cout << "Joe and Frank make the same amount\n";

    frank.wage += 5000.0;
    ++joe.age;

    return EXIT_SUCCESS;
}