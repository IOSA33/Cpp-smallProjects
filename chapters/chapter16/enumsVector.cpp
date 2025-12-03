#include <vector>
#include <cassert>
#include <type_traits>

namespace Students {
    enum Names : unsigned int { // explicitly unsigned int
        kenny,
        alisa,
        aurthur,
        max_students // always increases, if enum uses default values
    };
}

// Will not work for indicies, does not support conversion from StudentNames
// to std::size_t
enum class StudentNames {
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4
    max_students // 5
};

 // A better choice in C++23 is to use std::to_underlying() 
 // which converts an enumerator to a value of
 // the underlying type of the enumeratio

constexpr auto operator+(StudentNames a) noexcept {
    return static_cast<std::underlying_type_t<StudentNames>>(a);
}

int main() {
    // Create a vector with 4 elements
    std::vector<int> testScores(Students::max_students); 
    Students::Names name { Students::alisa }; // non-constexpr

    // Vector is not a constexpr container but array, C style are
    // Use assert for non-expr containers and static_assert for consexpr
    assert(std::size(testScores) == Students::max_students);

    // Using operator + to static cast enum class to size_t
    std::vector<int> test1(+StudentNames::max_students);
    test1[+StudentNames::kyle] = 98;

    testScores[name] = 78;

    return 0;
}