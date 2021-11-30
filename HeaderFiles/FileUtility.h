//
// Created by User on 11/25/2021.
//

#ifndef GRAPHMODULEC___FILEUTILITY_H
#define GRAPHMODULEC___FILEUTILITY_H

#include <stdlib.h>
#include <vector>
#include <fstream>
#include "HeaderFiles/AdjListW.h"
#include "HeaderFiles/AdjList.h"
#include <time.h>
#include "HeaderFiles/AdjMatrix.h"

int randomNumber(int min, int max){
    //max exclusive
    srand(time(NULL));
    return min + rand() % (max - min);
}

AdjListW generateWtGraphFromFile(const char* _filename, bool isDirected){

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

    return {isDirected, static_cast<unsigned int>(nodeNumber), static_cast<unsigned int>(edgeNumber), edgeList};
}

AdjListW generateWtGraphFromNonWtFile(const char* _filename, bool isDirected){

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
        readableFile >> edgeList[i][0] >> edgeList[i][1];
        edgeList[i][2] = 0;
    }
    readableFile.close();

    return {isDirected, static_cast<unsigned int>(nodeNumber), static_cast<unsigned int>(edgeNumber), edgeList};
}

AdjList generateGraphFromFile(const char* _filename){
    std::ifstream readableFile;
    readableFile.open(_filename);
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

void generateRandomGraph(bool isDirected, unsigned nodeNumber, double density, const char* _filename){
    std::ofstream writingFile;
    writingFile.open(_filename);
    if(!writingFile) {
        std::cout << "Unable to open file";
        exit(1);
    }
    AdjListW graph(isDirected, nodeNumber, 0, std::vector<std::vector<double>>(0));

    for(int i = 0; i < nodeNumber; i++){
    }
}
#endif //GRAPHMODULEC___FILEUTILITY_H
