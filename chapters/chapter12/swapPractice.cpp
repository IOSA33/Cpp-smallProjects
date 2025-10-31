#include <iostream>

void sort2(int& x, int& y) {
    if (x > y) {
        const int temp = y;
        y = x;
        x = temp;
    }
}

int main() {
    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return EXIT_SUCCESS;
}