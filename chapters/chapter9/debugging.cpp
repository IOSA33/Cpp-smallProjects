#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
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

// So basically here if we want to retest things later
// This requires you to remember what the expected answer was at worst (assuming you didn’t document it),
// and manually compare the actual results to the expected results. This is not what we wanted.
void testisLowerVowel() {
    std::cout << isLowerVowel('a') << '\n'; // temporary test code, should produce 1
    std::cout << isLowerVowel('q') << '\n'; // temporary test code, should produce 0
}

// We can do better by writing a test function that contains both the tests
// AND the expected answers and compares them so we don’t have to.
// returns the number of the test that failed, or 0 if all tests passed
int testVowel()
{
    if (!isLowerVowel('o')) return 1;
    if (isLowerVowel('q')) return 2;
    if (!isLowerVowel('e')) return 3;

    // Returns 0 if all tests passed
    return 0;
}


int main() {
    // Returning 1, because it is true
    std::cout << isLowerVowel('a') << "\n";
    testisLowerVowel();

    int result { testVowel() };
    if (result != 0)
        std::cout << "testVowel() test " << result << " failed.\n";
    else
        std::cout << "testVowel() tests passed.\n";

    return 0;
}
