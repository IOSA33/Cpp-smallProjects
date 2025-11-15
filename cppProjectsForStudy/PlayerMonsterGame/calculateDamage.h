#ifndef CALCULATEDAMAGE_H
#define CALCULATEDAMAGE_H
#include "Player.h"
#include "Monster.h"

class calculateDamage {
    public:
    static int attackCalculate(Player::TypeMagic magicType, Monster::Type monsterType);
};

#endif //CALCULATEDAMAGE_H
