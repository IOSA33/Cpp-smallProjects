#ifndef PLAYER_H
#define PLAYER_H

#include "Monster.h"

struct HealPotion {
    int hpRegen{ 70 };
    int amount{ 0 };
};

class Player {
public:
    enum TypeMagic {
        sword,  // + 35% for attack any enemy
        fire,   // + 70% for attack ice enemy
        ice,    // + 70% for attack fire enemy
    };

private:
    int m_hp{ 100 };
    TypeMagic m_type{};
    bool m_armor{}; //  If armor it reduce enemy attack by 20%.
    HealPotion m_healPotion{};

public:
    Player(const int hp, const TypeMagic magic, const bool armor, const HealPotion& healPotion)
        : m_hp(hp), m_type(magic), m_armor(armor), m_healPotion(healPotion) {}

    void attackEnemy(Monster& monster);
    int getHP() const { return m_hp; }
    void setHP(const int hp) { m_hp = hp; }
};

#endif //PLAYER_H
