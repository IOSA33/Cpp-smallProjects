#include <iostream>
#include <bits/ostream.tcc>

void printInt(int x ) {
    std::cout << x << std::endl;
}

// = delete means "I forbid this", not "this does not exist"
void printInt(char) = delete;
void printInt(bool) = delete;

int main() {
    printInt(10);
    printInt('a'); // compile error: function deleted
    printInt(true); // compile error: function deleted

    printInt(5.0);  // compile error: ambiguous match
    return 0;
}
