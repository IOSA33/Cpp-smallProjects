#include <iostream>
#include <string>
#include <random>
#include <set>
#include <algorithm>
#include <vector>

int samaaMerkki(const std::string& merkkijono) {
    if (merkkijono.empty()) {
        return 0;
    }
    int result{1};

    for (int i = 1; i < merkkijono.size(); i++) {
        if (merkkijono[i] == merkkijono[i - 1]) {
            ++result;
            if (merkkijono[i] != merkkijono[i + 1]) {
                return result;
            }
        }
    }

    return 0;
}

int calculateDifference(int array[]) {
    int result{};
    int smallest{array[0]};
    int largest{};

    for (int i = 0; i < sizeof(array); i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
        if (array[i] > largest) {
            largest = array[i];
        }
    }

    result = largest - smallest;

    return result;
}

int howManyInt(const std::multiset<int>& ms1, const int a, const int b) {
    int result{};

    if (a > b) {
        std::cout << "a:" << a << " is greater than b:" << b << std::endl;
        return 0;
    }

    const auto it_low = ms1.lower_bound(a);
    const auto it_high = ms1.upper_bound(b);
    result = static_cast<int>(std::distance(it_low, it_high));

    return result;
}

int howManyInt(std::vector<int>& v1, const int a, const int b) {
    int result{};

    if (a > b) {
        std::cout << "a:" << a << " is greater than b:" << b << std::endl;
        return 0;
    }

    const auto it_low = std::ranges::lower_bound(v1.begin(), v1.end(), a);
    const auto it_high = std::ranges::upper_bound(v1.begin(), v1.end(), b);
    result = static_cast<int>(std::distance(it_low, it_high));

    return result;
}

int main() {
    // int array[10] = {1, 2, 23, 4, 5, 6, 7, 11, 9, 10};
    // std::cout << calculateDifference(array) << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,100);

    std::multiset<int> ms1;
    std::vector<int> v1;
    v1.reserve(100);
    for (int i = 0; i < 100; ++i) {
        int insertion = dist(gen);
        ms1.insert(insertion);
        v1.emplace_back(insertion);
    }
    std::ranges::sort(v1);

    std::cout << "Set [0, 10]: " << howManyInt(ms1, 0, 10) << '\n';
    std::cout << "Vector [0, 10]: " << howManyInt(v1, 0, 10) << '\n';
    std::cout << "[50, 100]: " << howManyInt(ms1, 50, 100) << '\n';
    std::cout << "[67, 75]: " << howManyInt(ms1, 67, 75) << std::endl;

    return EXIT_SUCCESS;
}