//
// Created by User on 11/25/2021.
//

#ifndef GRAPHMODULEC___ADJLISTW_H
#define GRAPHMODULEC___ADJLISTW_H

#include "CustomExceptions.h"
#include <vector>
#include <stack>
#include <queue>

struct edge{
    unsigned source;
    unsigned destination;
    double weight;
};

class AdjListW {

private:
    std::vector<std::vector<edge>> adjList;
    const bool isDirected;
    unsigned nodeNumber;
    unsigned edgeNumber;

public:

    //constructor
    AdjListW(bool isDirected, unsigned int nodeNumber, unsigned int edgeNumber, std::vector<std::vector<double>> edgeList);

};


#endif //GRAPHMODULEC___ADJLISTW_H
