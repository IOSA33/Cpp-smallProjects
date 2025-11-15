#include <iostream>
#include "Monster.h"
#include "Player.h"

int main() {
    Player player1{100, Player::TypeMagic::sword, true, {.hpRegen = 70, .amount = 2}};
    Monster dragon{1200, Monster::dragon, 90};

    dragon.getType();

    std::cout << "Player1's HP: " << player1.getHP() << std::endl;
    std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;

    return 0;
}