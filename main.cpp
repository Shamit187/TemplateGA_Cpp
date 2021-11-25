#include <iostream>
#include "HeaderFiles/AdjList.h"
#include "HeaderFiles/AdjListW.h"
#include "HeaderFiles/FileUtility.h"

int main() {
    AdjListW graph = generateWtGraphFromFile("../Input/Graph_input_wt.txt");
    std::vector<int> output = graph.BFS(0, ADJLST_COLOR);
    for(auto i: output){
        std::cout << i << " ";
    } std::cout << std::endl;
    output = graph.DFS(0, ADJLST_DISCOVER);
    for(auto i: output){
        std::cout << i << " ";
    } std::cout << std::endl;


    return 0;
}
