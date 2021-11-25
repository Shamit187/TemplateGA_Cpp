#include <iostream>
#include "AdjList.h"
#include <fstream>

int main() {

    /* input module for no wt */
    /*
    int nodeNumber;
    int edgeNumber;

    std::vector<std::vector<unsigned>> edgeList;
    std::cin >> nodeNumber >> edgeNumber;
    edgeList.resize(edgeNumber, std::vector<unsigned>(2));

    for(int i = 0; i < edgeNumber; i++) {
        std::cin >> edgeList[i][0] >> edgeList[i][1];
    }
    */

    /* input module from file no wt*/
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

    AdjList graph(true, nodeNumber, edgeNumber, edgeList);
    //std::cout << graph;
    //std::cout << graph.bfsTree(0);
    std::vector<AdjList> Forrest = graph.bfsForrest();
    for(auto &tree : Forrest){
        std::cout << tree << std::endl;
    }


    return 0;
}
