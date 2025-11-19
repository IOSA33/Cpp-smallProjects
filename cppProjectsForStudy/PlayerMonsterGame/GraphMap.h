#ifndef GRAPHMAP_H
#define GRAPHMAP_H

#include <map>
#include <list>
#include <string>

class City{
    std::string m_name{};
    int m_population{};
    bool m_visited { false };

public:
    City(const std::string_view name, const int population, const bool visited)
    : m_name(name), m_population(population), m_visited(visited) {}

    std::string getName() const { return m_name; }
    int getPopulation() const {return m_population;};
    bool isVisited() const {return m_visited;};
};


class GraphMap {
    // We init a map with a first value as node and the second will be
    // a linked list that will represent other nodes that is connected
    // with the node.
    std::map<City*, std::list<City*> > m_city;

public:
    void setCityOnMap(City* x, City* y);
    void printGraph() const;
};

#endif //GRAPHMAP_H
