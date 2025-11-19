#ifndef GRAPHMAP_H
#define GRAPHMAP_H

#include <map>
#include <list>

class City {
    int population{};
    bool visited{};
};


class GraphMap {
    // We init a map with a first value as node and the second will be
    // a linked list that will represent other nodes that is connected
    // with the node.
    std::map<int, std::list<int> > m_city;

public:
    void setCityOnMap(const int x, const int y);
    void printGraph() const;
};

#endif //GRAPHMAP_H
