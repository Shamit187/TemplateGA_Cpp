#include <iostream>
#include "HeaderFiles/AdjList.h"
#include "HeaderFiles/AdjListW.h"
#include "HeaderFiles/FileUtility.h"
#include "HeaderFiles/AdjMatrix.h"

int main() {

    //generateRandomGraph(10, 12, "../Input/input_2.txt");


    AdjListW graph = generateWtGraphFromFile("../Input/input_2.txt",true);
    std::cout << graph.isConnected() << std::endl;
    /*
    std::cout << graph.BFSTree(0);
    std::cout << graph.DFSTree(0);

    try {
        auto set = graph.bipartiteSet();
        for(int i = 0; i < 2; i++){
            std::cout << "Set " << i << ": \n";
            for(auto v: set[i]){
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
     */
    /*
    try{
        std::vector<int> sortList = graph.topologicalSort();
        for(auto v: sortList){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    */



    return 0;
}
