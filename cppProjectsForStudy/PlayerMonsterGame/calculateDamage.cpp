#include "calculateDamage.h"

int calculateDamage::attackCalculate(Player::TypeMagic magicType, Monster::Type monsterType) {
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
