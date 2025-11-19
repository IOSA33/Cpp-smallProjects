#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "GraphMap.h"

int main() {
    Player player{100, Player::sword, true, {.hpRegen = 70, .amount = 2}, 25};
    Monster dragon{1200, Monster::dragon, 90};
    GraphMap g;
    City* c1 = new City{"The castle", 12500, false};
    City* c2 = new City{"The boiled", 405, false};
    City* c3 = new City{"Closest sun", 1023, false};
    g.setCityOnMap(c1, c2);
    g.setCityOnMap(c1, c3);
    g.printGraph();

    std::cout << "You are currently in " << c1->getName() << " Where do you wanna go?" << std::endl;
    std::cout << c2->getName() << " or to the " << c3->getName() << std::endl;

    int input{};
    std::cin >> input;
    if (input == 1) {

        g.setVisited(c2);
        std::cout << "Current map is: \n";
        g.printGraph();

        std::cout << "Oh no the dragon is attacking!!!\n";

        std::cout << "Player's HP: " << player.getHP() << std::endl;
        std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;

        player.attackEnemy(dragon);
        std::cout << "Dragon's HP: " << dragon.getHP() << std::endl;
        dragon.attackEnemy(player);
        std::cout << "Player's HP: " << player.getHP() << std::endl;

        player.useHeal();
    }

    return 0;
}