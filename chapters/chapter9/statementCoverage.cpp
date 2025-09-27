#include <iostream>

// Calling this function as foo(1, 0) will give you complete statement coverage
// for this function, as every statement in the function will execute.
int foo(int x, int y) {
    int z{y};
    if (x>y) {
        z = x;
    }
    return z;
}

// Here we need 3 calls to get 100% branch coverage
void compare(int x, int y)
{
    if (x > y)
        std::cout << x << " is greater than " << y << '\n'; // case 1
    else if (x < y)
        std::cout << x << " is less than " << y << '\n'; // case 2
    else
        std::cout << x << " is equal to " << y << '\n'; // case 3
}

// BEST PRACTICE