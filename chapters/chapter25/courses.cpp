#include <vector>
#include <iostream>

double gpa(const std::vector<int>& vec) {
    if (vec.empty()) return 0;
    double sum {};
    for (const auto& i: vec) {
        sum += i;
    }

    return sum / static_cast<double>(vec.size());
}

int main() {
    //                        olio                                  algo
    std::vector<int> vec{5,1,  4,  3,3,5,3,3,5,5,3,3,4,5,4,5,4,5,5,  5,  5,5,5,5};
    std::cout << "GPA: " << gpa(vec) << std::endl;
}