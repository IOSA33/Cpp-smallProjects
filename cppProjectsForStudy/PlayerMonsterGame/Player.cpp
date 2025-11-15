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

void Player::useHeal() {
    if (m_hp < 70 && m_healPotion.amount > 0) {
        setHP(m_hp + m_healPotion.hpRegen);
        std::cout << m_hp << " ";
        if (m_hp > 100) {
            m_hp -= static_cast<int>(m_hp) % 100;
            std::cout << "HP is above max. " << "Now it's again HP: " << m_hp << '\n';
        }
        std::cout << "You are healed!\n";
    } else {
        std::cout <<"Not enough heal potions!\n";
    }
}

