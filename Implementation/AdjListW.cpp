//
// Created by User on 11/25/2021.
//
#include "../HeaderFiles/AdjListW.h"

AdjListW::AdjListW(bool isDirected, unsigned int nodeNumber, unsigned int edgeNumber, std::vector<std::vector<double>> edgeList)
: isDirected(isDirected),nodeNumber(nodeNumber),edgeNumber(edgeNumber) {
    adjList.resize(nodeNumber, std::vector<edge>(0));

    for(int i = 0; i < edgeNumber; i++){
        unsigned v = edgeList[i][0];
        unsigned u = edgeList[i][1];
        double wt = edgeList[i][2];

        adjList[v].push_back(edge{v, u, wt});
        if(!isDirected) adjList[u].push_back(edge{u, v, wt});
    }
}
