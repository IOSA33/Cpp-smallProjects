#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "GraphMap.h"

int main() {
    Player player{100, Player::sword, true, {.hpRegen = 70, .amount = 2}, 25};
    Monster dragon{1200, Monster::dragon, 90};
    GraphMap g;
    City* c1 = new City{"The castle", 12500, true};
    City* c2 = new City{"The boiled", 405, false};
    City* c3 = new City{"Closest sun", 1023, false};
    g.setCityOnMap(c1, c2);
    g.setCityOnMap(c1, c3);
    g.printGraph();

    std::cout << "You are currently in \"" << c1->getName() << "\" Where do you wanna go?" << "\n";
    std::cout << "\"" << c2->getName() << "\" or to the \"" << c3->getName() << "\"\n";

    int input{};
    std::cin >> input;
    if (input == 1) {

        g.setVisited(c2);
        g.printGraph();

        std::cout << "Oh no, the dragon is attacking!!!\n";

        std::cout << "Player's HP: " << player.getHP() << "\n";
        std::cout << "Dragon's HP: " << dragon.getHP() << "\n";

        player.attackEnemy(dragon);
        std::cout << "Dragon's HP: " << dragon.getHP() << "\n";
        dragon.attackEnemy(player);
        std::cout << "Player's HP: " << player.getHP() << std::endl;

        std::cout << "Do You want to use Heal Potion? You have: " << player.getHealAmount() << std::endl;
        int input{};
        std::cin >> input;
        if (input == 1) {
            player.useHeal();
        }
    }

    std::cout << "You survived :), Congratulations!" << std::endl;

    return 0;
}