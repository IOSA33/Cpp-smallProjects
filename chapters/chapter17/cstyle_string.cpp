#include <iostream>
#include <cstring>

int main() {
    constexpr char str[] { "Hello" };

    const char* begin {str};
    const char* end{str + std::strlen(str)};
    for (; begin != end; ++begin) {
        std::cout << *begin << '\n';
    }

    begin = str;
    std::cout << "\nSecond:";
    while (*begin != '\0') {
        std::cout << *begin;
        ++begin;
    }

    begin = str;
    std::cout << "\nThird:";
    for (; end!=begin-1; --end) {
        std::cout << *end;
    }

    begin = str;
    while (*begin != '\0') {
        ++begin;
    }
    std::cout << "\nFourth:";
    while (begin-- != str) {
        std::cout << *begin;
    }

}