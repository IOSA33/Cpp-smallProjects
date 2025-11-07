#include <iostream>

struct Monster {
    enum MonsterType {
        ogre,
        dragon,
        orc,
        giantSpider,
        slime,
    };

    MonsterType type{};
    std::string name{};
    int health{};
};

std::string_view getMonsterTypeName(const Monster::MonsterType type) {
    switch (type) {
        case Monster::ogre:
            return "ogre";
        case Monster::dragon:
            return "dragon";
        case Monster::orc:
            return "orc";
        case Monster::giantSpider:
            return "giantSpider";
        case Monster::slime:
            return "slime";
    }
    return "Unknown?";
}

void printMonster(const Monster& monster) {
    std::cout << "This " << getMonsterTypeName(monster.type) <<
        " is named "<< monster.name << " and has " << monster.health <<
        " health." << std::endl;
}

int main() {
    const Monster dragonS10 {Monster::MonsterType::dragon, "DragonS10", 10900};
    const Monster slime10 {.type = Monster::MonsterType::slime, .name = "Slime 10 lvl", .health = 920};
    printMonster(dragonS10);
    printMonster(slime10);

    return EXIT_SUCCESS;
}