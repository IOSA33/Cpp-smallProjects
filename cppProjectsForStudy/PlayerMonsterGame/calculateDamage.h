#ifndef CALCULATEDAMAGE_H
#define CALCULATEDAMAGE_H

#include "Player.h"
#include "Monster.h"

class CalculateDamage {
public:
    static int attackCalculate(Player::TypeMagic magicType, Monster::Type monsterType);
};

inline int CalculateDamage::attackCalculate(Player::TypeMagic magicType, Monster::Type monsterType) {
    if (magicType == Player::sword) {
        return 45;  // returning 45% to attack
    }
    if (magicType == Player::ice && monsterType == Monster::dragon) {
        return 70;
    }
    if (magicType == Player::fire && monsterType == Monster::goblin || monsterType == Monster::ork) {
        return 70;
    }
    return 1; // default damage
}


#endif //CALCULATEDAMAGE_H
