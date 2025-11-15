#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "calculateDamage.h"

void Player::attackEnemy(Monster& monster) {
    const double percentageOfDamage = CalculateDamage::attackCalculate(m_type, monster.getType());
    const double percent = percentageOfDamage / 100;
    const double attack = percent*m_attack+m_attack;
    std::cout <<"Attack: "<< m_attack <<", sum of attack " << attack << '\n';

    monster.setHP(monster.getHP()-attack);
}
