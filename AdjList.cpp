//
// Created by User on 11/24/2021.
//

#include "AdjList.h"

AdjList::AdjList(bool isDirected, unsigned nodeNumber, unsigned edgeNumber, std::vector<std::vector<unsigned>> edgeList)
: nodeNumber(nodeNumber), edgeNumber(edgeNumber), isDirected(isDirected) {
    adjList.resize(nodeNumber, std::vector<unsigned>(0));

    for(int i = 0; i < edgeNumber; i++){
        unsigned v = edgeList[i][0];
        unsigned u = edgeList[i][1];

        adjList[v].push_back(u);
        if(!isDirected) adjList[u].push_back(v);
    }
}

AdjList::~AdjList() {

}
