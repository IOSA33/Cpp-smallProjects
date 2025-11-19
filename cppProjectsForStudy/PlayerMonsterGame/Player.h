#ifndef PLAYER_H
#define PLAYER_H

class Monster;

struct HealPotion {
    double hpRegen{ 70 };
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
    double m_hp{ 100 };
    TypeMagic m_type{};
    bool m_armor{}; //  If armor it reduce enemy attack by 20%.
    HealPotion m_healPotion{};
    int m_attack{};

public:
    Player(const double hp, const TypeMagic magic, const bool armor, const HealPotion& healPotion, const int attack)
        : m_hp(hp),
        m_type(magic),
        m_armor(armor),
        m_healPotion(healPotion),
        m_attack(attack){
    }

    void attackEnemy(Monster& monster);

    double getHP() const { return m_hp; }
    void setHP(const int hp) { m_hp = hp; }
    bool getArmor() const { return m_armor; }
    void setArmor(const bool armor) { m_armor = armor; }
    void useHeal();
    int getHealAmount() const {return m_healPotion.amount; }
};

#endif //PLAYER_H
