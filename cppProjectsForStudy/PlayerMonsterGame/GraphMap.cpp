#include "GraphMap.h"

#include <iostream>
#include <bits/ostream.tcc>

void GraphMap::setCityOnMap(const int x, const int y) {
    std::cout << x << ", " << y << std::endl;
    // Adding the edge between x and y
    m_city[x].emplace_back(y);
    // Adding the edge between y and x, for undirected graph
    m_city[y].emplace_back(x);
}

void GraphMap::printGraph() const {
    std::cout << "Graph of the map" << std::endl;
    for (const auto&[fst, snd]: m_city) {
        std::cout << fst << " -> ";
        for (const auto j: snd) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    GraphMap g;
    g.setCityOnMap(0, 1);
    g.setCityOnMap(0, 2);
    g.printGraph();
    return 0;
}
