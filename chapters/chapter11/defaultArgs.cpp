#include <iostream>

void print(int x, int y=10) // 10 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

// Where to use, example:
int rollDie(int sides=6);
void openLogFile(std::string filename="default.log");

int main() {
    print(10); // y will be 10
    print(20, 11); // y will be 11
}

// Example 2:

// foo.h
// #ifndef FOO_H
// #define FOO_H
// void print(int x, int y=4); // We putting it here the y=4
// #endif

#include <iostream>

void print(int x, int y); // forward declaration, no default argument

int main()
{
    print(3, 7); // compile error: default argument for y hasn't been defined yet

    return 0;
}

void print(int x, int y)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}