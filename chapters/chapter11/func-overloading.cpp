#include <iostream>
//Function overloading provides a great way to reduce the
//complexity of your program by reducing the number of function
//names you need to remember. It can and should be used liberally.

// We can use same name, but difference is in parameters
int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

int add(int x, int y, int z) {
    return x + y + z;
}

int main() {
    add(1, 2);
    std::cout<< add(3.53, 4.353);
    return 0;
}