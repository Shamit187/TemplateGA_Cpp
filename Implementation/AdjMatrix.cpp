//
// Created by User on 11/25/2021.
//

#include "../HeaderFiles/AdjMatrix.h"

AdjMatrix::AdjMatrix(unsigned nodeNumber, unsigned edgeNumber,bool isDirected, std::vector<std::vector<double>> edgeList)
: nodeNumber(nodeNumber), edgeNumber(edgeNumber), isDirected(isDirected) {
    adjMatrix.resize(nodeNumber, std::vector<double>(nodeNumber));

    for(int i = 0; i < edgeNumber; i++){
        unsigned v = edgeList[i][0];
        unsigned u = edgeList[i][1];
        double wt = edgeList[i][2];

        adjMatrix[v][u] = wt;
        if(!isDirected) adjMatrix[u][v] = wt;
    }
}
