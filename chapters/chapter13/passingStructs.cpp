#include <iostream>

struct Employee
{
    int id {}; // The value initialization
    int age {};
    double wage {};
};

// note pass by reference here
void printEmployee(const Employee& employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe { .age  = 32, .wage = 24.15 };
    Employee frank { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(joe);

    std::cout << '\n';

    // Print Frank's information
    printEmployee(frank);

    return 0;
}