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

    for (const auto& [key, value]: _u) {
        std::cout << key << " : " << value << std::endl;
    }

    return 0;
}