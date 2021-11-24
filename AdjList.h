//
// Created by User on 11/24/2021.
//

#ifndef GRAPHMODULEC___ADJLIST_H
#define GRAPHMODULEC___ADJLIST_H

#include <vector>

class AdjList {
private:
    std::vector<std::vector<unsigned>> adjList;
    const unsigned nodeNumber;
    unsigned edgeNumber;
    const bool isDirected;

public:
    AdjList(bool isDirected, unsigned nodeNumber, unsigned edgeNumber, unsigned** edgeList);

    virtual ~AdjList();
};


#endif //GRAPHMODULEC___ADJLIST_H
