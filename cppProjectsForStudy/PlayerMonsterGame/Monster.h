#ifndef MONSTER_H
#define MONSTER_H

class Player;

class Monster {
public:
    enum Type {
        goblin,
        dragon,
        ork,
    };

private:
    double m_hp{};
    Type m_type{};
    int attack{};

public:
    Monster(const double hp, const Type type, int attack = 90) : m_hp(hp), m_type(type) {}
    Type getType() const { return m_type; }
    double getHP() const { return m_hp; }
    void setHP(const double hp) { m_hp = hp; }
    // void attackEnemy(const Player& player);
};

#endif //MONSTER_H
