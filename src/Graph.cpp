//
// Created by David on 31/10/2020.
//

#include "../headers/Graph.h"
#include <vector>
// TODO test this
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix) , infected(std::vector<bool> (edges.size(),false)) {}
Graph::Graph() {};
Graph::Graph(const Graph &g) : edges(g.edges),infected(g.infected){};
bool Graph::isInfected(int nodeInd) {
    return infected[nodeInd];
}

void Graph::infectNode(int nodeInd) {
    this->infected[nodeInd] = true;
}

void Graph::isolateNode(int nodeInd) {
    for (int i = 0; i<edges.size();i++){
        this->edges[nodeInd][i]=0;
        this->edges[i][nodeInd]=0;
    }
}





