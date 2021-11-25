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

std::vector<int> AdjListW::BFS(unsigned int source, int returnType) {
    std::vector<int> color;
    color.resize(nodeNumber, ADJLST_WHITE);

    std::vector<int> distance;
    distance.resize(nodeNumber, ADJLST_INF);

    std::vector<int> parent;
    parent.resize(nodeNumber, ADJLST_INF);

    color[source] = ADJLST_GRAY;
    distance[source] = 0;

    std::queue<int> queue;
    queue.push(source);

    while(!queue.empty()){
        unsigned v = queue.front(); queue.pop();
        for(auto u: adjList[v]){
            if (color[u.destination] == ADJLST_WHITE){
                color[u.destination] = ADJLST_GRAY;
                distance[u.destination] = distance[v] + 1;
                parent[u.destination] = v;
                queue.push(u.destination);
            }
        }
        color[v] = ADJLST_BLACK;
    }
    if(returnType == ADJLST_DISTANCE){
        return distance;
    }else if(returnType == ADJLST_PARENT){
        return parent;
    }else if(returnType == ADJLST_COLOR){
        return color;
    }else{
        return std::vector<int>(0);
    }
}

std::vector<int> AdjListW::DFS(unsigned int source, int returnType) {
    std::stack<int> vertexStack;

    std::vector<int> color;
    color.resize(nodeNumber, ADJLST_WHITE);

    std::vector<int> discover;
    discover.resize(nodeNumber, ADJLST_INF);

    std::vector<int> finish;
    finish.resize(nodeNumber, ADJLST_INF);

    std::vector<int> parent;
    parent.resize(nodeNumber, ADJLST_INF);

    int time = 0;

    vertexStack.push(source);
    color[source] = ADJLST_GRAY;
    discover[source] = ++time;

    while(!vertexStack.empty()){
        int v = vertexStack.top(); vertexStack.pop();

        if (color[v] == ADJLST_GRAY){

            color[v] = ADJLST_GREEN;
            vertexStack.push(v);

            for(auto u: adjList[v]){
                if(color[u.destination] == ADJLST_WHITE){
                    color[u.destination] = ADJLST_GRAY;
                    discover[u.destination] = ++time;
                    vertexStack.push(u.destination);
                    parent[u.destination] = v;
                }
            }

        }else if(color[v] == ADJLST_GREEN){
            color[v] = ADJLST_BLACK;
            finish[v] = ++time;
        }
    }

    switch (returnType) {
        case ADJLST_COLOR:
            return color;
        case ADJLST_DISCOVER:
            return discover;
        case ADJLST_FINISH:
            return finish;
        case ADJLST_PARENT:
            return parent;
        default:
            return std::vector<int>(0);
    }
}
