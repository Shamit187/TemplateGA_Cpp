//
// Created by User on 11/25/2021.
//

#ifndef GRAPHMODULEC___ADJMATRIX_H
#define GRAPHMODULEC___ADJMATRIX_H

#include <vector>

class AdjMatrix {

private:

    std::vector<std::vector<double>> adjMatrix;
    const unsigned nodeNumber;
    unsigned edgeNumber;
    const bool isDirected;

public:

    //constructor
    AdjMatrix(unsigned nodeNumber, unsigned edgeNumber, bool isDirected, std::vector<std::vector<double>> edgeList);

    //Utility

    //BFS

    //DFS
};


#endif //GRAPHMODULEC___ADJMATRIX_H
