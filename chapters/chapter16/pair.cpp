#include <utility>
#include <vector>
#include <iostream>
#include <limits>

template <typename T>
std::pair<std::size_t, std::size_t> returnPair(const std::vector<T>& v) {
    std::size_t minIndex{}; 
    std::size_t maxIndex{};

    for (std::size_t i { 0 }; i < v.size(); ++i) {
        if (v[i] < v[minIndex]) {
            minIndex = i;
        }
        if (v[i] > v[maxIndex]) {
            maxIndex = i;
        }
    }

    return { minIndex, maxIndex };
}

int main() {

    std::vector<int> v;
    v.reserve(15);

    while (true) {
        std::cout << "Enter numbers to add (use -1 to stop): \n";
        int x{};
        std::cin >> x;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            continue;
        }

        if (x == -1) {
            break;
        }

        v.push_back(x);
    }
    
    auto pair1 { returnPair(v) };

    std::cout << "The min element has index " << pair1.first<<" and value " <<v[pair1.first]<<"\n";
    std::cout << "The max element has index " << pair1.second<<" and value " <<v[pair1.second]<<"\n";
    return 0;
}