#include <iostream>
#include "Player.h"
#include "Monster.h"

void Monster::attackEnemy(Player& player) {
    double defaultAttack{ m_attack };
    if (player.getArmor()) {
        defaultAttack -= m_attack * 0.65;
    }

    std::cout <<"Attack: "<< m_attack <<", sum of attack " << defaultAttack << '\n';

    player.setHP(player.getHP()-defaultAttack);
}
