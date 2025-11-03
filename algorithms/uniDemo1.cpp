#include <iostream>
#include <string>
#include <random>
#include <set>

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

int howManyInt(std::multiset<int>& s1, int a, int b) {
    int result{};

    while (a < b) {
        auto it = s1.find(a);
        if (it != s1.end()) {
            std::cout << "Element found: " << *it << std::endl;
            ++result;
        }
        ++a;
    }

    return result;
}

int main() {
    // int array[10] = {1, 2, 23, 4, 5, 6, 7, 11, 9, 10};
    // std::cout << calculateDifference(array) << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,100);

    std::multiset<int> ms1;
    for (int i = 0; i < 100; ++i) {
        ms1.insert(dist(gen));
    }

    std::cout << "[0, 10]: " << howManyInt(ms1, 0, 10) << '\n';

    return EXIT_SUCCESS;
}