#include <utility>
#include <vector>
#include <iostream>

template <typename T>
std::pair<std::pair<T, T>, std::pair<T, T>> returnPair(const std::vector<T>& v) {
    T min{ v[0] };
    T minIndex{}; 
    T max{ v[0] };
    T maxIndex{};

    for (size_t i { 0 }; i < v.size(); ++i) {
        if (v[i] > max) {
            minIndex = static_cast<T>(i);
            max = v[i];
        }
        if (v[i] < min) {
            maxIndex = static_cast<T>(i);
            min = v[i];
        }
    }

    return std::make_pair(std::make_pair(min, minIndex), std::make_pair(max, maxIndex));
}

int main() {

    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    
    auto pair1 { returnPair(v1) };
    auto pair2 { returnPair(v2) };

    std::cout << "The min element has index " << pair1.first.second<<" and value " <<pair1.first.first<<"\n";
    std::cout << "The max element has index " << pair1.second.second<<" and value " <<pair1.second.first<<"\n";
    std::cout << std::endl;
    std::cout << "The min element has index " << pair2.first.second<<" and value " <<pair2.first.first<<"\n";
    std::cout << "The max element has index " << pair2.second.second<<" and value " <<pair2.second.first<<"\n";

    return 0;
}