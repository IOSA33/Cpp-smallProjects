#include <iostream>
#include "Monster.h"
#include "Player.h"

int main() {
    Player player{100, Player::TypeMagic::sword, true, {.hpRegen = 70, .amount = 2}, 25};
    Monster dragon{1200, Monster::dragon, 90};

    std::cout << "Player's HP: " << player.getHP() << std::endl;
    std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;

    player.attackEnemy(dragon);
    std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;
    dragon.attackEnemy(player);
    std::cout << "Player's HP: " << player.getHP() << std::endl;

    player.useHeal();

    return 0;
}