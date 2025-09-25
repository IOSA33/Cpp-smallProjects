#include <iostream>

bool isLowerVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

// Now we added test cases for later. So basically here if we want to retest things later
void testisLowerVowel() {
    std::cout << isLowerVowel('a') << '\n'; // temporary test code, should produce 1
    std::cout << isLowerVowel('q') << '\n'; // temporary test code, should produce 0
}


int main() {
    // Returning 1, because it is true
    std::cout << isLowerVowel('a') << "\n";

    return EXIT_SUCCESS;
}
