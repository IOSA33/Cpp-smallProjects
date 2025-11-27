#include <vector>
#include <iostream>
#include <cassert>

namespace PlayerInventory {
    enum Items {
        healthPotion,
        torch,
        arrow,
        size_inventory
    };
}

int main() {
    std::vector<int> invecntory{ 1, 5, 10 };

    assert(std::size(invecntory) == PlayerInventory::size_inventory);

    int totalItems{};
    for (const auto& i: invecntory) {
        totalItems += i;
    };

    std::cout << totalItems << std::endl;
    return 0;
}