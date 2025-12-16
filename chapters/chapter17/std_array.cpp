#include <array>
#include <iostream>

struct Item {
    std::string_view name;
    int gold;
};

constexpr std::array arr{Item{"Sword", 5}, Item{"dagger", 3}, Item{"club", 2}, Item{"spear", 7}};

const Item* infoItem(std::string_view name) {
    for (auto& i : arr) {
        if (i.name == name) {
            return &i;
        }
    }

    return nullptr;
}

int main() {
    const Item* item { infoItem("no") };
    std::cout << (item ? item->name : "Nobody");
}