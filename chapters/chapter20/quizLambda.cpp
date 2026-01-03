#include <iostream>
#include <array>
#include <string>
#include <algorithm>


struct Student
{
    std::string_view name{};
    int points{};
};

int main() {
    std::array<Student, 8> arr{
    { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    auto best = [](Student& s1, Student& s2) -> bool {
        if (s1.points < s2.points) {
            return true;
        }
        return false;
    };

    auto* it = std::max_element(arr.begin(), arr.end(), best);
    std::cout << it->name << std::endl;
}
