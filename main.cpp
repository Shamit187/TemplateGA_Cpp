#include <iostream>
#include "HeaderFiles/AdjList.h"
#include "HeaderFiles/AdjListW.h"
#include "HeaderFiles/FileUtility.h"
#include "HeaderFiles/AdjMatrix.h"

int main() {

//    AdjListW graph = generateWtGraphFromFile("../Input/input_1.txt",false);
//    //std::cout << graph.BFSTree(0);
//
//    try {
//        auto set = graph.bipartiteSet();
//        for(int i = 0; i < 2; i++){
//            std::cout << "Set " << i << ": \n";
//            for(auto v: set[i]){
//                std::cout << v << " ";
//            }
//            std::cout << std::endl;
//        }
//    }catch(std::exception &e){
//        std::cout << e.what() << std::endl;
//    }
    generateRandomGraph(10, 5, "../Input/input_2.txt");
    AdjListW graph = generateWtGraphFromFile("../Input/input_2.txt", false);
    std::cout << graph.isConnected() << std::endl;
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

    return 0;
}
