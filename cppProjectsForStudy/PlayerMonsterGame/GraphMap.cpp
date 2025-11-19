#include "GraphMap.h"
#include <iostream>

void GraphMap::setCityOnMap(City* x, City* y) {
    // Adding the edge between x and y
    m_city[x].emplace_back(y);
    // Adding the edge between y and x, for undirected graph
    m_city[y].emplace_back(x);

    if (m_city.contains(x) && !m_city[x].empty()) {
        std::cout << x->getPopulation() << ", " << y->getPopulation() << std::endl;
    }

}

void GraphMap::printGraph() const {
    std::cout << "Graph of the map" << std::endl;
    for (const auto&[fst, snd]: m_city) {
        std::cout << fst->getName() << " -> ";
        for (const auto j: snd) {
            std::cout << "The road to the " << j->getName() << " is visited:" << j->isVisited() << ". ";
        }
        std::cout << std::endl;
    }
}

void GraphMap::setVisited(City *x) {
    x->setVisited();
    std::cout << x->getName() << " is now visited! Congrats!" << std::endl;
}

// int main() {
//     GraphMap g;
//     City* c1 = new City{"The castle", 12500, true};
//     City* c2 = new City{"The boiled", 405, false};
//     City* c3 = new City{"Closest sun", 1023, false};
//
//     g.setCityOnMap(c1, c2);
//     g.setCityOnMap(c1, c3);
//     g.printGraph();
//     g.setVisited(c2);
//     g.printGraph();
//
//     delete c1;
//     delete c2;
//     delete c3;
//
//     return 0;
// }
