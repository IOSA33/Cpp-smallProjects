#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for std::abort

// This function will require two calls to test all the statements, as there is no way to reach
// statement 2 and 3 in the same function call.
bool isLowerVowel(char c)
{
    switch (c) // Statement 1
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true; // Statement 2
        default:
            return false; // Statement 3
    }
}

// So basically here if we want to retest things later
// This requires you to remember what the expected answer was at worst (assuming you didn’t document it),
// and manually compare the actual results to the expected results. This is not what we wanted.
void testVowel() {
    std::cout << isLowerVowel('a') << '\n'; // temporary test code, should produce 1
    std::cout << isLowerVowel('q') << '\n'; // temporary test code, should produce 0
}

// We can do better by writing a test function that contains both the tests
// AND the expected answers and compares them so we don’t have to.
// returns the number of the test that failed, or 0 if all tests passed
int testVowel1()
{
    // Returns number of the test that didn't pass.
    if (!isLowerVowel('o')) return 1;
    if (isLowerVowel('q')) return 2;
    if (!isLowerVowel('e')) return 3;

    // Returns 0 if all tests passed
    return 0;
}

// Program will halt on any failed test case
int testVowel2() {
#ifdef NDEBUG
    // If NDEBUG is defined, asserts are compiled out.
    // Since this function requires asserts to not be compiled out, we'll terminate the program if this function is called when NDEBUG is defined.
    std::cerr << "Tests run with NDEBUG defined (asserts compiled out)";
    std::abort();
#endif

    assert(isLowerVowel('a'));
    assert(isLowerVowel('e'));
    assert(isLowerVowel('i'));
    assert(isLowerVowel('o'));
    assert(isLowerVowel('u'));
    assert(!isLowerVowel('b'));
    assert(isLowerVowel('q'));
    assert(!isLowerVowel('y'));
    assert(!isLowerVowel('z'));

    return 0;
}

int main() {
    // Returning 1, because it is true
    std::cout << isLowerVowel('a') << "\n";

    // First test
    testVowel();

    // Test for better tests
    int result { testVowel1() };
    if (result != 0)
        std::cout << "testVowel() test " << result << " failed.\n";
    else
        std::cout << "testVowel() tests passed.\n";

    // Advanced test handler
    testVowel2();
    // If we reached here, all tests must have passed
    std::cout << "All tests succeeded\n";

    return 0;
}
