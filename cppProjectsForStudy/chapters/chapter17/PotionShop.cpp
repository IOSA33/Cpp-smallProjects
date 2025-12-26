#include <iostream>
#include <array>
#include <string>
#include <cassert>
#include <random>

int randomGold();

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_potion
    };

    constexpr std::array<Potion::Type, max_potion> types{healing, mana, speed, invisibility};
    constexpr std::array<std::string_view, max_potion> names {"healing", "mana", "speed", "invisibility"};
    constexpr std::array<int, max_potion> cost {20, 30, 12, 50};

    static_assert(std::size(types) == max_potion);
    static_assert(std::size(names) == max_potion);
    static_assert(std::size(cost) == max_potion);
};

class Player {
    std::string m_name{};
    int m_gold{};
    std::array<int, Potion::Type::max_potion> m_inventory{}; 

public:
    Player(std::string_view name) 
        : m_name(name), m_gold(randomGold()) {}

    void setInventory(size_t position) {
        if (position >= 0 && position < Potion::max_potion) {
            ++m_inventory[position];
        } else {
            std::cout << "You cant access out of Inventory :)\n";
        }
    }
    int gold() const { return m_gold; }
    void buy(int cost) {
        m_gold -= cost;
    }
    void printInventory() {
        std::cout << "\nYour inventory contains: \n";
        for (size_t i = 0; i < m_inventory.size(); ++i) {
            if (m_inventory[i] > 0)
                std::cout << m_inventory[i] << "x potion of " << Potion::names[i] << '\n';
        }
        std::cout << "You escaped with " << m_gold << " gold remaining.\n\n";
    }
};


int randomGold() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(80, 120);

    return dist(gen);
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charToInt(char c) {
    return c - '0';
}

void shop(Player& player) {
    while (true) {
        std::cout << "\nHere is our selection for today:\n";
        for (const auto& i: Potion::types) {
            std::cout << i << ") " << Potion::names[i] << " costs " << Potion::cost[i] << '\n';
        }
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        char input{};
        std::cin >> input;

        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "You spelled something wrong. Try again!\n";
            continue;
        }
        
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "I didn't understand what you said.  Try again: \n";
            ignoreLine();
            continue;
        }

        if (input == 'q') {
            return;
        }

        ignoreLine();
        size_t positionOfPotion{static_cast<size_t>(charToInt(input))};
        if (positionOfPotion >= Potion::max_potion) {
            continue;
        }

        if (player.gold() < Potion::cost[positionOfPotion]) {
            std::cout << "\nYou can not afford that.\n";
            continue;
        } else {
            player.buy(Potion::cost[positionOfPotion]);
            player.setInventory(positionOfPotion);
            std::cout << "\nYou purchased a potion of " << Potion::names[positionOfPotion] << ". ";
            std::cout << "You have " << player.gold() << " gold left.\n";
        }
    }
}

int main() {
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    std::string name{};
    while (name.empty()) {
        std::cout << "Enter your name: ";
        std::getline(std::cin >> std::ws, name);
    }
        
    Player player{ name };
    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";
    shop(player);
    std::cout << std::endl;
    player.printInventory();
    std::cout << std::endl;

    std::cout << "Thanks for shopping at Roscoe's potion emporium!" << std::endl;
}