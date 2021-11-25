//
// Created by User on 11/25/2021.
//

#ifndef GRAPHMODULEC___ADJLISTW_H
#define GRAPHMODULEC___ADJLISTW_H

#include "CustomExceptions.h"
#include <vector>
#include <stack>
#include <queue>

#define ADJLST_WHITE 0
#define ADJLST_GRAY 1
#define ADJLST_BLACK 2
#define ADJLST_GREEN 3

#define ADJLST_INF -1

#define ADJLST_DISTANCE 0
#define ADJLST_PARENT 1
#define ADJLST_COLOR 2
#define ADJLST_DISCOVER 3
#define ADJLST_FINISH 4

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

    //Utility

    //BFS Algorithms
    std::vector<int> BFS(unsigned source, int returnType);

    //DFS Algorithms
    std::vector<int> DFS(unsigned int source, int returnType);
};


#endif //GRAPHMODULEC___ADJLISTW_H
