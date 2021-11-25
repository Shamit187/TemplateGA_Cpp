//
// Created by User on 11/25/2021.
//

#ifndef GRAPHMODULEC___FILEUTILITY_H
#define GRAPHMODULEC___FILEUTILITY_H

#include <vector>
#include <fstream>
#include "AdjListW.h"
#include "AdjList.h"

AdjListW generateWtGraphFromFile(const char* _filename){

    std::ifstream readableFile;
    readableFile.open(_filename);

    if (!readableFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    int nodeNumber;
    int edgeNumber;

    std::vector<std::vector<double>> edgeList;
    readableFile >> nodeNumber >> edgeNumber;
    edgeList.resize(edgeNumber, std::vector<double>(3));

    for(int i = 0; i < edgeNumber; i++) {
        readableFile >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
    }
    readableFile.close();

    return {true, static_cast<unsigned int>(nodeNumber), static_cast<unsigned int>(edgeNumber), edgeList};
}

AdjList generateGraphFromFile(const char* _filename){
    std::ifstream readableFile;
    readableFile.open("../Graph_input.txt");
    if (!readableFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int nodeNumber;
    int edgeNumber;

    std::vector<std::vector<unsigned>> edgeList;
    readableFile >> nodeNumber >> edgeNumber;
    edgeList.resize(edgeNumber, std::vector<unsigned>(2));

    for(int i = 0; i < edgeNumber; i++) {
        readableFile >> edgeList[i][0] >> edgeList[i][1];
    }
    readableFile.close();

    return {true, static_cast<unsigned int>(nodeNumber), static_cast<unsigned int>(edgeNumber), edgeList};
}


#endif //GRAPHMODULEC___FILEUTILITY_H
