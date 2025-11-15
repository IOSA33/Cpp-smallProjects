#include <iostream>
#include "Monster.h"
#include "Player.h"

int main() {
    Player player{100, Player::TypeMagic::sword, true, {.hpRegen = 70, .amount = 2}, 25};
    Monster dragon{1200, Monster::dragon, 90};

    std::cout << "Player1's HP: " << player.getHP() << std::endl;
    std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;

    player.attackEnemy(dragon);

    std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;
    return 0;
}