#include "GraphMap.h"
#include <iostream>

void GraphMap::setCityOnMap(City* x, City* y) {
    // Adding the edge between x and y
    m_city[x].emplace_back(y);
    // Adding the edge between y and x, for undirected graph
    m_city[y].emplace_back(x);
}

void GraphMap::printGraph() const {
    std::cout << "Graph of the map:" << std::endl;
    for (const auto&[fst, snd]: m_city) {
        std::cout << fst->getName() << " -> ";
        for (const auto j: snd) {
            if (j->isVisited() == false) {
                std::cout << "The road to the \"" << j->getName() << "\", Population is null, \n";
                continue;
            }
            std::cout << "The road to the " << j->getName() << ", Population is " << j->getPopulation() << "\n";
        }
        std::cout << std::endl;
    }
}

void GraphMap::setVisited(City *x) {
    x->setVisited();
    std::cout << "\""<< x->getName() << "\" is now visited! Congrats!" << std::endl;
}