#include <iostream>
#include <unordered_map>
#include <string>




int main() {

    // scope : grade
    std::unordered_map<int, int> _u {
        {
            {5, 5},
            {4, 5}
        }
    };

    for (const auto& i: _u) {
        std::cout << i.first << " : " << i.second << std::endl;
    }

    return 0;
}